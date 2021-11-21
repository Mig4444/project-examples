/*
 * ControllerTask.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#include <stdio.h>

#include "ControllerTask.h"
#include "ModelTask.h"

/* Private Methods*/

void controller_program_increase();
void controller_intensity_increase();
void controller_intensity_decrease();
void controller_program_reset();
void controller_device_state();
void controller_program_state();

/*! \brief Controller class method
 * 		   This method serves as a constructor, first time its called
 * 		   This method serves as a mean to retrieve the unique instance of Controller
 */
controller_s *controller_get_instance()
{
	static controller_s* controller_instance_m = NULL;

	if(NULL == controller_instance_m)
	{
		controller_instance_m = (controller_s*)malloc(sizeof(controller_s));
		controller_instance_m->device_on_off = &controller_device_state;
		controller_instance_m->intensity_decrease = &controller_intensity_decrease ;
		controller_instance_m->intensity_increase = &controller_intensity_increase ;
		controller_instance_m->program_increase = &controller_program_increase ;
		controller_instance_m->program_reset = &controller_program_reset ;
		controller_instance_m->program_state = &controller_program_state ;
	}
	else
	{
		/* Nothing to do*/
	}
	return controller_instance_m;
}

/*! \brief 	Logic when increasing the program
 *			When increasing the program a rollover is implemented
 */
void controller_program_increase()
{
	model_s *model_m = model_get_instance();
	uint8_t progConf = model_m->get_value_program();

	if(PROGRAM_MAX == progConf)
	{
		model_m->set_value_program(PROGRAM_MIN);
	}
	else
	{
		model_m->set_value_program(progConf+1);
	}
}

/*! \brief	Logic when increasing the intensity
 * 			Increases the intensity value by one.
 *			When increase is requested and maximum is reached or
 *			an incorrect superior value is detected
 *			Then the intensity value fixed to Maximum Intensity value
 */
void controller_intensity_increase ()
{
	model_s *model = model_get_instance();
	uint8_t intensity = model->get_value_intensity();

	/* Safety also on model, Avoid Rollover. E.g value 255*/
	if(INTENSITY_MAX <= intensity)
	{
		model->set_value_intensity(INTENSITY_MAX);
	}
	else
	{
		model->set_value_intensity(intensity+1);
	}
}

/*! \brief	Logic when decreasing the intensity
 * 			Decreases the intensity value by one.
 *			When decrease is requested and minimum is reached or
 *			an incorrect inferior value is detected
 *			Then the intensity value fixed to Minimum Intensity value
 *			Minimum value is mostly used for future evolutions
 */
void controller_intensity_decrease ()
{
	model_s *model_m = model_get_instance();
	uint8_t intensity_m = model_m->get_value_intensity();

	if(INTENSITY_MIN >= intensity_m)
	{
		model_m->set_value_intensity(INTENSITY_MIN);
	}
	else
	{
		model_m->set_value_intensity(intensity_m-1);
	}
}

/*! \brief	Logic when the program is reseted
 * 			Passing the device to Config state
 */
void controller_program_reset ()
{
	model_s *model = model_get_instance();
	model->set_value_state(Config);
}

/*! \brief	Logic when the program passes from
 * 			Config -> Run
 * 			Run -> Pause
 * 			or
 * 			Pause -> Run
 */
void controller_program_state()
{
	model_s *model = model_get_instance();
	programState_e state = model->get_value_state();

	switch(state)
	{
		case Config:
			printf("Running\n");
			model->set_value_state(Run);
			break;
		case Run:
			printf("Pause\n");
			model->set_value_state(Pause);
			break;
		case Pause:
			printf("Running\n");
			model->set_value_state(Run);
			break;
		default:
			printf("Default\n");
			model->set_value_state(Config);
			break;
	}
}

/*! \brief 	Logic when the device is turned Off or On
 *			This is entirely a simulation
 */
void controller_device_state ()
{
	model_s *model = model_get_instance();
	if(	model->get_device_state() == On)
	{
		model->set_device_state(Off);
	}
	else if( model->get_device_state() == Off)
	{
		model->set_device_state(On);
	}
	else
	{
		/* Nothing to do */
	}
}

/*! \brief	Destroy the current instance of the Controller
 */
void controller_destroy_instance()
{
	free(controller_get_instance());
}
