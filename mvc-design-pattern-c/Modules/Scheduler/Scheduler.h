/*
 * Scheduler.h
 *
 *  Created on: 20 nov. 2021
 *      Author: mig
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "../../Modules/Scheduler/Scheduler.h"

#include <time.h>
#include <sys/times.h>

#include "../../Modules/GlobalFiles/typeslocal.h"

#define STOPWATCH_NB_MAX 25

typedef struct
{
	bool_t stopWathUsed;
	clock_t count;
	uint16_t timeLimit;
	uint8_t reached;
}Stopwatch_t;

static Stopwatch_t stopWatch[STOPWATCH_NB_MAX];//ct0, ct1;
static uint8_t currStopwatches = 0;
struct tms tms;

clock_t getClockTime();
void initSchedulers();

#endif /* SCHEDULER_H_ */
