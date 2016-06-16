#include "Game.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "DishManager.h"
#include "TimerManager.h"
#include "LetterManager.h"
#include "GameObjectFactory.h"
#include "MenuButton.h"
#include "MainMenuState.h"
#include "Graphic.h"
#include "InputHandler.h"
#include <Windows.h>
#include "Dish.h"

Game* Game::s_pInstance = 0;

const int FRAMES_PER_SECOND = 60;
SDL_Event evt = SDL_Event();

//bool isClick();
//bool checkDish(Dish* _target);

bool Game::init(const char* _title, int _xPos, int _yPos, int _width, int _height, bool _fullScreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(_title, _xPos, _yPos, _width, _height, _fullScreen);

		if (m_pWindow != 0)
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	}
	else {
		return false;
	}

	TheGameObjectFactory::Instance()->registerType("Dish", new DishCreator());
	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator);
	TheGameObjectFactory::Instance()->registerType("Graphic", new GraphicCreator());

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());
	
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	//TextureManager::instance()->load("Resources/sprite.png", "sprite", m_pRenderer);
	//TextureManager::instance()->load("Resources/dish.png", "dish1", m_pRenderer);
	//TextureManager::instance()->load("Resources/dish.png", "dish2", m_pRenderer);
	//TextureManager::instance()->load("Resources/dish.png", "dish3", m_pRenderer);
	//TextureManager::instance()->load("Resources/blank.png", "blank", m_pRenderer);

	AudioManager::Instance()->init();
	AudioManager::Instance()->openAudio("Resources/bgm2.wav");

	/* variable init */
	mSceneType = SceneType::MAIN;
	mScore = 0;

	LetterManager::Instance()->init();
	AudioManager::Instance()->playBGM();

	return true;
}

void Game::render() {
	//TextureManager::instance()->draw("dish", 0, 0, 128, 82, m_pRenderer);

	// 사용예정
	//delegate_render(m_pRenderer);
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	m_pGameStateMachine->update();
	//SDL_RenderClear(m_pRenderer);

	//switch (mSceneType) {
	//case SceneType::MAIN:
	//	this->sceneMain();
	//	break;
	//case SceneType::GAME:
	//	this->sceneGame();
	//	break;
	//case SceneType::RESULT:
	//	this->sceneResult();
	//	break;
	//default:
	//	break;
	//}


	////mCurrentFrame = int(((SDL_GetTicks() / 100) % 30));
	//
	//// 게임 프레임 설정
	////if ((TimerManager::instance()->getTicks()) < (1000 / FRAMES_PER_SECOND))
	//	//SDL_Delay((1000 / FRAMES_PER_SECOND) - TimerManager::instance()->getTicks());
	//SDL_Delay(1000 / FRAMES_PER_SECOND);
}

void Game::clean() {
	delete TextureManager::Instance();
	delete DishManager::Instance();
	delete AudioManager::Instance();
	delete LetterManager::Instance();

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		mRunning = false;
	}
}

void Game::sceneMain() {
	/*Position button_position = { (SCREEN_WIDTH / 2) - (110 / 2), (SCREEN_HEIGHT / 2) - (58 / 2) };

	SDL_Rect title_rect = { 0, 0, 376, 75 };
	SDL_Rect button_rect[2] = { { 151, 100, 110, 58 }, { 0, 100, 110, 58 } };

	TextureManager::instance()->draw("sprite", SCREEN_WIDTH / 2 - 188, 50, title_rect.w, title_rect.h, m_pRenderer, &title_rect);

	if ((evt.motion.x >= button_position.x) && (evt.motion.x <= button_position.x + button_rect[1].w) &&
		(evt.motion.y >= button_position.y) && (evt.motion.y <= button_position.y + button_rect[1].h)) {
		TextureManager::instance()->draw("sprite", button_position.x, button_position.y, button_rect[1].w, button_rect[1].h, m_pRenderer, &button_rect[1]);
		if (isClick()) {
			mSceneType = SceneType::GAME;
		}
	}
	else
		TextureManager::instance()->draw("sprite", button_position.x, button_position.y, button_rect[0].w, button_rect[0].h, m_pRenderer, &button_rect[0]);*/
}

void Game::sceneGame() {
	//static int click_tick = 0;
	//static int tick = -1000;
	//static Position mouse_pos;
	//bool brk = false;

	//SDL_ShowCursor(SDL_DISABLE);

	//DishManager::instance()->update(m_pRenderer);

	//if (isClick()) {
	//	for (int i = DishManager::instance()->SIZE-1; i >= 0; --i) {
	//		mouse_pos.x = evt.button.x - 8;
	//		mouse_pos.y = evt.button.y - 8;
	//		tick = SDL_GetTicks();

	//		if (checkDish(DishManager::instance()->getDish(i))) {
	//			TextureManager::instance()->draw("blank", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, m_pRenderer);
	//			DishManager::instance()->getDish(i)->reset();
	//			++mScore;
	//			brk = true;
	//			AudioManager::instance()->playEffect();
	//			break;
	//		}
	//	}
	//	if (!brk) {
	//		LetterManager::instance()->createLetter(mScore, m_pRenderer);
	//		SDL_ShowCursor(SDL_ENABLE);
	//		printf("부순 접시 수 : %d\n", mScore);
	//		mScore = 0;
	//		mSceneType = SceneType::RESULT;
	//	}
	//}
	//SDL_Rect click_rect = { 356, 138, 20, 20 };
	//if (SDL_GetTicks() - tick < 200)
	//	TextureManager::instance()->draw("sprite", mouse_pos.x, mouse_pos.y, click_rect.w, click_rect.h, m_pRenderer, &click_rect);
}

void Game::sceneResult() {
	//TextureManager::instance()->draw(LetterManager::instance()->getLetter(), SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 60, 120, 120, m_pRenderer);
	//

	//if (isClick())
	//	mSceneType = SceneType::MAIN;
}

//bool checkDish(Dish* _target) {
	//float distance = 0.0f;

	//distance = (float)(
	//	(evt.button.x - (_target->getPosition().x + (_target->getDiameter() / 2))) *
	//	(evt.button.x - (_target->getPosition().x + (_target->getDiameter() / 2)))
	//	) + (float)(
	//	(evt.button.y - (_target->getPosition().y + (_target->getDiameter() / 2))) *
	//	(evt.button.y - (_target->getPosition().y + (_target->getDiameter() / 2)))
	//	);

	//if (distance <= (float)((_target->getDiameter() / 2) * (_target->getDiameter() / 2)))
	//	return true;
	//else
		//return false;
//}

// 단일클릭만 지원
//bool isClick() {
//	if (evt.type != SDL_MOUSEBUTTONDOWN)
//		return false;
//
//	bool isClicked = false;
//	
//	if (evt.type == SDL_MOUSEBUTTONDOWN) {
//		if (evt.button.button == SDL_BUTTON_LEFT) {
//			evt.type = SDL_BUTTON_MIDDLE;
//			return true;
//		}
//	}
//	return false;
//}