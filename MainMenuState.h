#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include <vector>
#include <string>
#include "MenuState.h"

class GameObject;

class MainMenuState : public MenuState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const std::string s_menuID;
};

#endif