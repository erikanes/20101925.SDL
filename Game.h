#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include "GameStateMachine.h"
//#include <functional> delegate사용을 위함. std::function<void(SDL_Renderer*)> 식으로 하면 됨

enum SceneType { MAIN, GAME, RESULT };

class Game {
public:
	Game() { mRunning = true; }
	~Game() {}
	bool init(const char* _title, int _xPos, int _yPos, int _width, int _height, bool _fullScreen = false);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return mRunning; }
	SDL_Renderer* getRenderer() const {
		return m_pRenderer;
	}
	GameStateMachine* getStateMachine() const {
		return m_pGameStateMachine;
	}
	void quit() {
		mRunning = false;
	}

	void sceneMain();
	void sceneGame();
	void sceneResult();

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	int getScore() {
		return m_score;
	}
	void setScore(int score) {
		m_score = score;
	}
	void addScore() {
		++m_score;
	}

private:
	static Game* s_pInstance;

	SDL_Window*		m_pWindow;
	SDL_Renderer*	m_pRenderer;
	SDL_Texture*	m_pTexture;
	SDL_Rect		mSourceRectangle;
	SDL_Rect		mDestinationRectangle;

	int				mCurrentFrame;
	int				mScore;
	bool			mRunning;
	SceneType		mSceneType;
	GameStateMachine* m_pGameStateMachine;

	int m_score;

	//std::function<void(SDL_Renderer*)> delegate_render;
} typedef TheGame;

#endif