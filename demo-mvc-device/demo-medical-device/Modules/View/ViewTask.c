/*
 * model.c
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#include <stdio.h>
#include <string.h>

#include "typeslocal.h"

#include "ViewTask.h"
#include "ModelTask.h"

/*Private methods prototypes
 * */
void view_display_value_program( );
void view_display_value_duration( );
void view_display_value_intensity( );
void view_display_value_hour( );
void view_display_value_minute();
void view_display_value_battery( );
void view_display_separation_line();

void view_draw();

/*! \brief View class method
 * 		   This method serves as a constructor, first time its called
 * 		   This method serves as a mean to retrieve the unique instance of View
 */
view_s* view_get_instance()
{
	static view_s *view_instance_m = NULL;

	if(view_instance_m == NULL)
	{
		view_instance_m = (view_s*)malloc(sizeof(view_s));
		view_instance_m->draw = &view_draw;
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
	printf("P%d ", model_get_instance()->get_value_program());
}


/*! \brief Display of duration value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_duration()
{
	printf("Dur. %d ",model_get_instance()->get_value_duration());
}


/*! \brief Display of intensity value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_intensity( )
{
	printf("Intens. %d%% ",model_get_instance()->get_value_intensity());
}


/*! \brief Display of hour value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_hour()
{
	printf("Hr. %d ",model_get_instance()->get_value_hour());
}

/*! \brief Display of minute value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_minute()
{
	printf(":%d ",model_get_instance()->get_value_minutes());
}


/*! \brief Display of battery value
 *         First version of a display function
 *         To be updated with a widget on a C++ Layer
 *         Callable inside the module
 *         Globally just a getter
 */

void view_display_value_battery()
{
	printf("Bat. %d%% ",model_get_instance()->get_value_battery());
}


/*! \brief Display of State
 *  	   States are Config Run Pause
 */

void view_display_value_state()
{
	printf("State. %d",model_get_instance()->get_value_state());
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
	view_display_value_minute();
	view_display_value_battery();
	view_display_value_state();
	view_display_separation_line();
}
