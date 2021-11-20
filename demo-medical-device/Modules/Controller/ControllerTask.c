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
	uint8_t progConf = model_m->get_value_program_ptr();

	if(PROGRAM_MAX == progConf)
	{
		model_m->set_value_program_ptr(PROGRAM_MIN);
	}
	else
	{
		model_m->set_value_program_ptr(progConf+1);
	}
}

/*! \brief
 *
 */
void controller_intensity_increase ()
{
	model_s *model = model_get_instance();
	uint8_t intensity = model->get_value_intensity_ptr();

	/* Safety also on model, Avoid Rollover. E.g value 255*/
	if(INTENSITY_MAX <= intensity)
	{
		model->set_value_intensity_ptr(INTENSITY_MAX);
	}
	else
	{
		model->set_value_intensity_ptr(intensity+1);
	}
}

/*! \brief
 *
 */
void controller_intensity_decrease ()
{
	model_s *model_m = model_get_instance();
	uint8_t intensity_m = model_m->get_value_intensity_ptr();

	if(INTENSITY_MIN >= intensity_m)
	{
		model_m->set_value_intensity_ptr(INTENSITY_MIN);
	}
	else
	{
		model_m->set_value_intensity_ptr(intensity_m-1);
	}
}

/*! \brief
 *
 */
void controller_program_reset ()
{
	model_s *model = model_get_instance();
	model->set_value_state_ptr(Config);
}

void controller_program_state()
{
	model_s *model = model_get_instance();
	programState_e state = model->get_value_state();

	switch(state)
	{
		case Config:
			model->set_value_state_ptr(Run);
			break;
		case Run:
			model->set_value_state_ptr(Pause);
			break;
		case Pause:
			model->set_value_state_ptr(Run);
			break;
		default:
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
