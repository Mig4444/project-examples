#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <UnitaryTests.h>

#include "typeslocal.h"
#include "Scheduler.h"

#include "ModelTask.h"
#include "ViewTask.h"
#include "ControllerTask.h"

int main()
{

#if 0
	executeAllTest();
#else
	// Launch threads
	createThreads();

	// Destroy all instances
	model_destroy_instance();
	view_destroy_instance();
	controller_destroy_instance();
#endif
	return 0;
}
