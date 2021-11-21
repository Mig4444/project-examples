/*
 * Scheduler.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "Scheduler.h"

#include "ModelTask.h"
#include "ViewTask.h"
#include "ControllerTask.h"

void scheduler_command_reception(uint8_t command);

/* brief/ Get system ticks
 *
 * */
clock_t getTick()
{
	return  times(&tms);
}

/* brief/ This function compares the previous and current time
 *
 * */
bool elapsedTime(clock_t previousTime, double msElapsedTime)
{
	bool result = false;
	clock_t currTime = getTick();
	if( (currTime > previousTime) &&
		(msElapsedTime <= (currTime - previousTime)) )
	{
		/* Time elapsed*/
		result = true;
	}
	else if(currTime < previousTime)
	{
		/* Timer rollover*/
		result = true;
	}
	else
	{
		/* Nothing to do*/
	}

	return result;
}

/* brief/ 	Function pointer used by the thread
 *			Established the frequency in which the view is refreshed
 * */
void *scheduler_view_thread()
{
	model_s *model = model_get_instance();
	while (model->get_device_state() == On)
	{
		clock_t previousTime = getTick();
		while( (false == elapsedTime(previousTime, WAIT_5S)) &&
			   (model->get_device_state() == On) )
		{

		}
		view_get_instance()->draw();
	}
	printf("Model is Off...Thanks for your attention\n");
}

/* brief/	Function pointer used by the thread
 *			This function retrieves the input commands from user
 * */
void *scheduler_controller_thread()
{
	uint8_t input;
	model_s *model = model_get_instance();
	while (model->get_device_state() == On)
	{
		scanf("%c",&input);
		scheduler_command_reception(input);
	}

}

/*! \brief Function that triggers the correct action in function of the inputs
 */
void scheduler_command_reception(uint8_t command)
{
	controller_s *controller = controller_get_instance(); // Constructor
	switch(command)
	{
	case '+':
		controller->intensity_increase();
		break;
	case '-':
		controller->intensity_decrease();
		break;
	case 'p':
	case 'P':
		controller->program_increase();
		break;
	case 's':
	case 'S':
		controller->program_state();
		break;
	case 'r':
	case 'R':
		controller->program_reset();
		break;
	case 'o':
	case 'O':
		controller->device_on_off();
		break;

	default:
		/*Nothing to do*/
		break;
	}
}

/* brief/ 	Creation of threads
 * 			Prints error if the thread was not created
 * 			Implements a join to wait for all threads to be finished
 * */
void createThreads()
{
	pthread_t view_thread;
	pthread_t controller_thread;

	int resultVT = pthread_create(&view_thread, NULL, &scheduler_view_thread ,NULL);
	if(resultVT==0)
	{
	    //Wait to exit from all threads
		printf("Thread View created\n");
	}
	else
	{
	    perror(" View Thread not created.\n");
	}

	int resultCT = pthread_create(&controller_thread, NULL, &scheduler_controller_thread ,NULL);
	if(resultCT==0)
	{
	    //Wait to exit from all threads
		printf("Thread Controller created\n");

	}
	else
	{
	    perror(" Controller Thread not created.\n");
	}

    pthread_join(controller_thread, NULL);
    pthread_join(view_thread, NULL);
}

