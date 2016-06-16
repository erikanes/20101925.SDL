#ifndef _MENUBUTTON_H_
#define _MENUBUTTON_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
//#include "InputHandler.h"

enum button_state {
	MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2
};

class LoaderParams;

class MenuButton : public SDLGameObject {
public:
	MenuButton();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }

private:
	void(*m_callback)();
	bool m_bReleased;
	int m_callbackID;
};

class MenuButtonCreator : public BaseCreator {
	GameObject* createGameObject() const {
		return new MenuButton();
	}
};

#endif