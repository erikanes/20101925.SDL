#include "MenuButton.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

MenuButton::MenuButton() : SDLGameObject() {}

void MenuButton::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
	SDLGameObject::draw();
}

void MenuButton::update() {
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width) && pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height) && pMousePos->getY() > m_position.getY()) {
		if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT) && m_bReleased) {
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT)) {
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else {
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean() {
	SDLGameObject::clean();
}