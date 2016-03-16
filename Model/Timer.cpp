/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: thod0127
 */

#include "Timer.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Default constructor.
 */
Timer::Timer()
{
	executionTime = 0;
}

/*
 * Default destructor not used at the moment.
 */
Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

/*
 * Returns the amount of microseconds the timer ran for as a string.
 */
void Timer::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << "The timer ran for " << executionTime << "μs (microseconds)" << endl;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC << " seconds." << endl;
}

/*
 * Starts the timer.
 */
void Timer::startTimer()
{
	executionTime = clock();
}

/*
 * Stops the timer
 */
void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}

/*
 * Resets the timer to 0 microseconds
 */
void Timer::resetTimer()
{
	executionTime = 0;
}

/*
 * Returns the timers execution time as a long in microseconds.
 */
long Timer::getExecutionTimeInMicroseconds()
{
	return executionTime;
}

