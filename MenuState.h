#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "GameState.h"
#include <string>
#include <vector>

class GameObject;

class MenuState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

	static void s_menuToPlay();
	static void s_exitFromMenu();

protected:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

	std::vector<Callback> m_callbacks;

private:
	static const std::string s_menuID;
};

#endif