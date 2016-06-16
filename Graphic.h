#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "GameObjectFactory.h"
#include "SDLGameObject.h"

class LoaderParams;

class Graphic : public SDLGameObject
{
public:
	Graphic();

	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

class GraphicCreator : public BaseCreator {
	GameObject* createGameObject() const {
		return new Graphic();
	}
};

#endif