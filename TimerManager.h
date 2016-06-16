#ifndef _TIMER_MANAGER_H_
#define _TIMER_MANAGER_H_

#include "SDL.h"

class TimerManager
{
public:
	static TimerManager* instance() {
		if (mInstance == 0)
			mInstance = new TimerManager();
		return mInstance;
	}

	//Initializes variables
	TimerManager();

	//The various clock actions
	void	start();

	void	stop();

	void	pause();

	void	unPause();

	//Gets the timer's time
	int		getTicks();

	//Checks the status of the timer
	bool	isStarted();

	bool	isPaused();

private:
	static TimerManager* mInstance;
	//The clock time when the timer started
	int		startTicks;
	//The ticks stored when the timer was paused
	int		pausedTicks;
	//The timer status
	bool	paused;
	bool	started;
};

#endif