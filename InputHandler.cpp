#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	m_mousePosition = new Vector2D(0.0f, 0.0f);
	for (int i = 0; i < 3; ++i) {
		m_mouseButtonStates.push_back(false);
	}
}

InputHandler::~InputHandler() {
}

void InputHandler::update() {
	SDL_Event evt;
	onMouseButtonUp();
	while (SDL_PollEvent(&evt)) {
		switch (evt.type) {
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(evt);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(evt);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp();
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}

void InputHandler::clean() {
	delete m_mousePosition;
	m_mousePosition = NULL;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keystates != 0) {
		if (m_keystates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() {
	return m_mousePosition;
}

void InputHandler::onMouseMove(SDL_Event evt) {
	m_mousePosition->setX(static_cast<float>(evt.motion.x));
	m_mousePosition->setY(static_cast<float>(evt.motion.y));
}

void InputHandler::onMouseButtonDown(SDL_Event evt) {
	switch (evt.button.button) {
	case SDL_BUTTON_LEFT:
		m_mouseButtonStates[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		m_mouseButtonStates[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		m_mouseButtonStates[RIGHT] = true;
		break;
	}
}

void InputHandler::onMouseButtonUp() {
	for (int i = 0; i < 3; ++i) {
		m_mouseButtonStates[i] = false;
	}
}

void InputHandler::onKeyDown() {
	m_keystates = const_cast<Uint8*>(SDL_GetKeyboardState(0));
}

void InputHandler::onKeyUp() {
	m_keystates = const_cast<Uint8*>(SDL_GetKeyboardState(0));
}