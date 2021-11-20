/*
 * model.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#include <stdio.h>
#include "typeslocal.h"
#include "string.h"

#include "ViewTask.h"
#include "ModelTask.h"

/*Private methods prototypes
 * */
void view_display_value_program( );
void view_display_value_duration( );
void view_display_value_intensity( );
void view_display_value_hour( );
void view_display_value_battery( );
void view_display_separation_line();

void view_draw();

/*! \brief
 */

view_s* view_get_instance()
{
	static view_s *view_instance_m = NULL;

	if(view_instance_m == NULL)
	{
		view_instance_m = (view_s*)malloc(sizeof(view_s));
		view_instance_m->draw_ptr = &view_draw;
	}

	return view_instance_m;
}

void view_destroy_instance()
{
	free(view_get_instance());
}

/*! \brief Display of program value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_program( )
{
	printf("P%d ", model_get_instance()->get_value_program_ptr());
}


/*! \brief Display of duration value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_duration()
{
	printf("Dur. %d ",model_get_instance()->get_value_duration_ptr());
}


/*! \brief Display of intensity value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_intensity( )
{
	printf("Intens. %d%% ",model_get_instance()->get_value_intensity_ptr());
}


/*! \brief Display of hour value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_hour()
{
	printf("Hr. %d ",model_get_instance()->get_value_hour_ptr());
}


/*! \brief Display of battery value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_battery()
{
	printf("Bat. %d%%",model_get_instance()->get_value_battery_ptr());
}


/*! \brief Display of separation line
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Line of 80 characters
 *         Callable inside the module
 */

void view_display_separation_line()
{
	printf("\n");
}

/*! \brief drawView is a method meant to update the display
 */

void view_draw()
{
	view_display_value_program();
	view_display_value_duration();
	view_display_value_intensity();
	view_display_value_hour();
	view_display_value_battery();
	view_display_separation_line();
}
