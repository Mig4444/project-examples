#ifndef VIEWTASK_H_
#define VIEWTASK_H_

#include <stdlib.h>

typedef struct
{
	/* return void - Ptr*/
	void (*draw_ptr)();
	void (*set_duration_ptr)(uint8_t);
	void (*set_program_ptr)(uint8_t);
	void (*set_intensity_ptr)(uint8_t);
	void (*set_hour_ptr)(uint8_t);
	void (*set_battery_ptr)(uint8_t);
}view_s;

/* Public Method*/
view_s* view_get_instance();
void view_destroy_instance();

/* c limitation if viewtask of singleton is that
 * if a new declaration is done,
 * then a new instance is created

 * but handled itself
 * */

#endif /* VIEWTASK_H_ */
