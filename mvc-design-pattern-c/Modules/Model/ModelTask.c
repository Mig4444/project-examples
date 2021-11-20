/*
 * ModelTask.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#include <stdio.h>
#include <stdlib.h>
#include "typeslocal.h"
#include "string.h"

#include "ModelTask.h"

static uint8_t program_m;
static uint8_t duration_m;
static uint8_t intensity_m;
static uint8_t hour_m;
static uint8_t minutes_m;
static uint8_t battery_m;
static programState_e state_m;
static deviceState_e deviceState_m;

static bool_t modification_m;

void model_set_value_program(uint8_t program);
uint8_t model_get_value_program();
uint8_t model_get_value_duration();
void model_set_value_state(uint8_t state);
uint8_t model_get_value_state();
void model_set_value_intensity(uint8_t intensity);
uint8_t model_get_value_intensity();
uint8_t model_get_value_hour();
uint8_t model_get_value_minutes();
uint8_t model_get_value_battery();
void model_set_device_state(deviceState_e deviceState);
deviceState_e model_get_device_state();

/*! \brief
 */
model_s* model_get_instance()
{
	static model_s *model_instance_m = NULL;

	if(NULL == model_instance_m)
	{
		model_instance_m = (model_s*)malloc(sizeof(model_s));
		battery_m = 0;
		duration_m = 0;
		hour_m = 0;
		intensity_m = INTENSITY_MIN;
		program_m = PROGRAM_MIN;
		modification_m = false;
		state_m = Config;
		deviceState_m = On;

		model_instance_m->set_value_program_ptr = &model_set_value_program;
		model_instance_m->get_value_program_ptr = &model_get_value_program;
		model_instance_m->get_value_duration_ptr = &model_get_value_duration;
		model_instance_m->set_value_state_ptr = &model_set_value_state;
		model_instance_m->get_value_state = &model_get_value_state;
		model_instance_m->set_value_intensity_ptr = &model_set_value_intensity;
		model_instance_m->get_value_intensity_ptr = &model_get_value_intensity;
		model_instance_m->get_value_hour_ptr = &model_get_value_hour;
		model_instance_m->get_value_minutes_ptr = &model_get_value_minutes;
		model_instance_m->get_value_battery_ptr = &model_get_value_battery;
		model_instance_m->set_device_state = &model_set_device_state;
		model_instance_m->get_device_state = &model_get_device_state;

	}
	else
	{
		/* Nothing to do */
	}

	return model_instance_m;
}

/*! \brief
 */
void model_set_value_program(uint8_t program)
{
	/* Safety also on Controller Against defect of flash*/
	if((PROGRAM_MAX < program) || (PROGRAM_MIN > program))
	{
		program = PROGRAM_MIN;
	}
	else
	{
		/* Nothing to do */
	}
	//printf("model_set_value_program = P%d\n",program);
	program_m = program;
}

/*! \brief
 */
uint8_t model_get_value_program()
{
	//printf("model_get_value_program = P%d\n",program_m);
	return program_m;
}


/*! \brief
 */
uint8_t model_get_value_duration()
{
	//printf("model_get_value_duration = %d\n",duration_m);
	return duration_m;
}

/*! \brief
 */
void model_set_value_state(uint8_t state)
{
	//printf("model_set_value_state = %d\n",state);
	state_m = state;
	if(Config == state_m)
	{
		intensity_m = INTENSITY_MIN;
	}
	else
	{
		/* Nothing to do */
	}
}


/*! \brief
 */
uint8_t model_get_value_state()
{
	//printf("model_get_value_state = %d\n",state_m);
	return state_m;
}

/*! \brief
 */
void model_set_value_intensity(uint8_t intensity)
{
	/* Safety also on Controller Against defect of flash*/
	if(INTENSITY_MAX <= intensity)
	{
		intensity = INTENSITY_MAX;
	}
	else
	{
		/* Nothing to do */
	}
	//printf("model_set_value_intensity = %d\n",intensity);
	intensity_m = intensity;
}

/*! \brief
 */
uint8_t model_get_value_intensity()
{
	//printf("model_get_value_intensity = %d\n",intensity_m);
	return intensity_m;
}

/*! \brief
 */
uint8_t model_get_value_hour()
{
	//printf("model_get_value_hour = %d\n",hour_m);
	return hour_m;
}

/*! \brief
 */
uint8_t model_get_value_minutes()
{
	//printf("model_get_value_minutes = %d\n",minutes_m);
	return minutes_m;
}

/*! \brief
 */
uint8_t model_get_value_battery()
{
	//printf("model_get_value_battery = %d\n",battery_m);
	return battery_m;
}

/*! \brief
 */
deviceState_e model_get_device_state()
{
	return deviceState_m;
}

/*! \brief
 */
void model_set_device_state(deviceState_e deviceState)
{
	//printf("model_set_device_state = %d\n",deviceState);
	deviceState_m = deviceState;
}

/*! \brief
 */
void model_destroy_instance()
{
	free(model_get_instance());
}
