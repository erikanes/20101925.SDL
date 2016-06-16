#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

class InputHandler {
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

	void onMouseMove(SDL_Event evt);
	void onMouseButtonDown(SDL_Event evt);
	void onMouseButtonUp();
	void onKeyDown();
	void onKeyUp();

	enum mouse_buttons {
		LEFT = 0, MIDDLE = 1, RIGHT = 2
	};
private:
	InputHandler();
	~InputHandler();
	Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	static InputHandler* s_pInstance;
}typedef TheInputHandler;

#endif