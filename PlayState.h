#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "GameState.h"
#include "SDLGameObject.h"
#include <string>
#include <vector>

class GameObject;
class Dish;

class PlayState : public GameState {
public:
	
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	static void s_hitToDish();

private:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	std::vector<Callback> m_callbacks;

	static const std::string s_playID;
};

#endif