#include "Graphic.h"
#include "LoaderParams.h"
#include <SDL.h>

Graphic::Graphic() : SDLGameObject() {}

void Graphic::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
	m_currentFrame = 0;
}

void Graphic::draw() {
	SDLGameObject::draw();
}

void Graphic::update() {	
}

void Graphic::clean() {
	SDLGameObject::clean();
}