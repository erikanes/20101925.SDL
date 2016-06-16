#include "TimerManager.h"
#include <stdio.h>

TimerManager* TimerManager::mInstance = 0;

TimerManager::TimerManager()
{
	//Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;

	this->start();

	puts("TimerManager »ı¼º");
}

void TimerManager::start()
{
	//Start the TimerManager
	started = true;

	//Unpause the TimerManager
	paused = false;

	//Get the current clock time
	startTicks = SDL_GetTicks();
}

void TimerManager::stop()
{
	//Stop the TimerManager
	started = false;

	//Unpause the TimerManager
	paused = false;
}

void TimerManager::pause()
{
	//If the TimerManager is running and isn't already paused
	if ((started == true) && (paused == false))
	{
		//Pause the TimerManager
		paused = true;

		//Calculate the paused ticks
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void TimerManager::unPause()
{
	//If the TimerManager is paused
	if (paused == true)
	{
		//Unpause the TimerManager
		paused = false;

		//Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		//Reset the paused ticks
		pausedTicks = 0;
	}
}

int TimerManager::getTicks()
{
	//If the TimerManager is running
	if (started == true)
	{
		//If the TimerManager is paused
		if (paused == true)
		{
			//Return the number of ticks when the TimerManager was paused
			return pausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			return SDL_GetTicks() - startTicks;
		}
	}

	//If the TimerManager isn't running
	return 0;
}

bool TimerManager::isStarted()
{
	return started;
}

bool TimerManager::isPaused()
{
	return paused;
}