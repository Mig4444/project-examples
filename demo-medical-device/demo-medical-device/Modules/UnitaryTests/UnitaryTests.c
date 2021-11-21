/*
 * unitaryTests.c
 *
 *  Created on: 21 nov. 2021
 *      Author: mig
 */

#include "UnitaryTests.h"
#include "ModelTask.h"
#include "ViewTask.h"
#include "ControllerTask.h"

void viewTest()
{
	/* Test View*/
	view_get_instance(); // Constructor
	view_get_instance()->draw();
}

void modelTest()
{
	/* Test Model */
	model_get_instance(); // Constructor
	model_get_instance()->set_value_intensity(111);
	model_get_instance()->set_value_program(222);
	model_get_instance()->set_value_state(254);

	model_get_instance()->get_value_intensity();
	model_get_instance()->get_value_intensity();
	model_get_instance()->get_value_program();
	model_get_instance()->get_value_duration();
}

void controllerTest()
{
	/* Test Controller*/
	controller_get_instance();
	controller_get_instance()->intensity_increase();
	view_get_instance()->draw();
	controller_get_instance()->intensity_decrease();
	view_get_instance()->draw();
}

void executeAllTest()
{
	viewTest();
	modelTest();
	controllerTest();
}
