#ifndef CONTROLLERTASK_H_
#define CONTROLLERTASK_H_

#include <stdlib.h>

typedef struct
{
	void (*device_on_off)();
	void (*intensity_decrease)();
	void (*intensity_increase)();
	void (*program_increase)();
	void (*program_reset)();
	void (*program_state)();
	void (*device_state)();
}controller_s;


/* Public Methods*/
controller_s *controller_get_instance();
void controller_destroy_instance();

#endif /* CONTROLLERTASK_H_ */
