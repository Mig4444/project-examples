/*
 * ControllerTask.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#include "ControllerTask.h"
#include "ModelTask.h"

/* Private Methods*/

void controller_program_increase();
void controller_intensity_increase();
void controller_intensity_decrease();
void controller_program_reset();
void controller_device_state();
void controller_program_state();

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

/*! \brief
 *
 */
void controller_program_increase()
{
	//Read current value of program
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

/*! \brief
 *
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

/*! \brief
 *
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

/*! \brief
 *
 */
void controller_program_reset ()
{
	model_s *model = model_get_instance();
	model->set_value_state(Config);
}

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

/*! \brief
 *
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

/*! \brief
 */
void controller_destroy_instance()
{
	free(controller_get_instance());
}
