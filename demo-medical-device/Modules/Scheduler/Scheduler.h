/*
 * Scheduler.h
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <time.h>
#include <sys/times.h>

#include "typeslocal.h"

#define WAIT_10S	1000
#define WAIT_5S		500
#define WAIT_1S		100

typedef struct
{
	bool_t stopWathUsed;
	clock_t count;
	uint16_t timeLimit;
	uint8_t reached;
}Stopwatch_t;

struct tms tms;

clock_t getTick();
bool elapsedTime(clock_t previousTime, double msElapsedTime);
void scheduler_command_reception(uint8_t command);
void createThreads();

#endif /* SCHEDULER_H_ */
