/*
 * Scheduler.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */
#include "../../Modules/Scheduler/Scheduler.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* brief/ Get system ticks
 *
 * */
clock_t getTick()
{
	printf("Current tick is = %ld\n",times(&tms));
	return  times(&tms);
}

void setStopwatch(Stopwatch_t stopWatchInit[], uint16_t stopWatchTimeLimit_m)
{
	printf("Adding a new stopwatch ...\n");
	stopWatchInit->count = stopWatchTimeLimit_m;
	stopWatchInit->reached = false;
	currStopwatches++;
}

/* brief/ Initialize all the added stopwatches
 *
 * */

void initStopwatches()
{

	printf("Initializing stopwatches ...\n");
	for(int i = 0; i<currStopwatches;i++)
	{
		stopWatch[i].timeLimit = getTick();
		if(stopWatch[i].timeLimit == -1)
		{
			printf("ERROR: Incorreclty initialized Stopwatches number %d ",i);
		}
		else
		{
			printf("Correclty initialized Stopwatches number %d ",i);
		}
	}
}
