#ifndef MODELTASK_H_
#define MODELTASK_H_

#include "typeslocal.h"

#define INTENSITY_MAX 100
#define INTENSITY_MIN 0

#define PROGRAM_MIN	1
#define PROGRAM_MAX	6

typedef enum
{
	On,
	Off
} deviceState_e;

typedef struct
{
	void (*set_value_program)(uint8_t);
	uint8_t (*get_value_program)();
	uint8_t (*get_value_duration)();
	void (*set_value_state)(uint8_t);
	deviceState_e (*get_device_state)();
	void (*set_device_state)(deviceState_e);
	uint8_t (*get_value_state)();
	void (*set_value_intensity)(uint8_t);
	uint8_t (*get_value_intensity)();
	uint8_t (*get_value_hour)();
	uint8_t (*get_value_minutes)();
	uint8_t (*get_value_battery)();
} model_s;

typedef enum
{
	Config,
	Run,
	Pause
} programState_e;

/* Public Methods*/
model_s* model_get_instance();
void model_destroy_instance();

#endif /* MODELTASK_H_ */
