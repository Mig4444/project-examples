#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "Modules/GlobalFiles/typeslocal.h"
#include "Modules/Scheduler/Scheduler.h"

#include "Modules/Model/ModelTask.h"
#include "Modules/View/ViewTask.h"
#include "Modules/Controller/ControllerTask.h"

int main()
{
	/* Test View*/
	view_get_instance(); // Constructor
	view_get_instance()->draw_ptr();

	/* Test Model */
	model_get_instance(); // Constructor
	model_get_instance()->set_value_intensity_ptr(111);
	model_get_instance()->set_value_program_ptr(222);
	model_get_instance()->set_value_state_ptr(254);

	model_get_instance()->get_value_intensity_ptr();
	model_get_instance()->get_value_intensity_ptr();
	model_get_instance()->get_value_program_ptr();
	model_get_instance()->get_value_duration_ptr();

	/* Test Controller*/
	controller_get_instance();
	controller_get_instance()->intensity_increase();
	view_get_instance()->draw_ptr();
	controller_get_instance()->intensity_decrease();
	view_get_instance()->draw_ptr();

	// PThread for Model

	// PThread for View

	// PThread Controller

	// Destroy all instances
	model_destroy_instance();
	view_destroy_instance();
	controller_destroy_instance();

	return 0;
}
