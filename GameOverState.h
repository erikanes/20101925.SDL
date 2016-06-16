#ifndef _GAMEOVERSTATE_H_
#define _GAMEOVERSTATE_H_

#include <vector>
#include <iostream>
#include "MenuState.h"

class GameOverState : public MenuState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }

protected:
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:
	static void s_gameOverToMain();
	static void s_restartPlay(); //Reset PlayState

	static const std::string s_gameOverID;
};

#endif