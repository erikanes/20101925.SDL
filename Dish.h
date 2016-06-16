//#ifndef _DISH_H_
//#define _DISH_H_
//
//#include "GeneralData.h"
//#include <string>
//#include <SDL.h>
//
//class Dish {
//public:
//	Dish();
//	~Dish();
//	void init(std::string _id);
//
//	void reset();
//	Position getPosition() const;
//	int getDiameter() const;
//	SDL_Texture* getTexture() const;
//	int getAlpha();
//
//private:
//	SDL_Texture* mTexture;
//	Position mPosition;
//	int mDiameter;
//	int mAlpha;
//};
//
//
//#endif

#ifndef _DISH_H_
#define _DISH_H_

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
//#include "InputHandler.h"

class LoaderParams;

class Dish : public SDLGameObject {
public:
	Dish();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void init();
	void setDiameter(int _diameter) { m_diameter = _diameter; }
	int getDiameter() { return m_diameter; }

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
	void doCallback() { m_callback(); }

private:
	void(*m_callback)();
	int m_callbackID;
	bool m_bReleased;

	int createRandom(int min, int max);
	int m_diameter;
	int m_alpha;
};

class DishCreator : public BaseCreator {
	GameObject* createGameObject() const {
		return new Dish();
	}
};

#endif