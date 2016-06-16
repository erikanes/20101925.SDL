#include "PlayState.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Game.h"
#include "StateParser.h"
#include "GameOverState.h"
#include "TextureManager.h"
#include "StateParser.h"
#include "DishManager.h"
#include "Dish.h"
#include "AudioManager.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->update();
	}

	int count = 0;
	static int ticks = 0;

	for (int i = 2; i >= 0; --i) {
		if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT)) {
			ticks = SDL_GetTicks();
			TextureManager::Instance()->setAlpha("effect", 255);

			Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

			Dish* dish = dynamic_cast<Dish*>(m_gameObjects[i]);

			float x = dish->getPosition().getX();
			float y = dish->getPosition().getY();

			float distance = std::powf(pMousePos->getX() - (x + (dish->getDiameter() / 2.0f)), 2.0f)
				+ std::powf(pMousePos->getY() - (y + (dish->getDiameter() / 2.0f)), 2.0f);

			if (distance <= std::powf(dish->getDiameter() / 2.0f, 2.0f)) {
				dish->doCallback();
				dish->init();

				SDLGameObject* go = static_cast<SDLGameObject*>(m_gameObjects[3]);
				go->getPosition().setX(TheInputHandler::Instance()->getMousePosition()->getX());
				go->getPosition().setY(TheInputHandler::Instance()->getMousePosition()->getY());
				break;
			}
			else {
				++count;
			}
		}
	}
	if (SDL_GetTicks() - ticks > 200) {
		TextureManager::Instance()->setAlpha("effect", 0);
	}
	if (count >= 3) {
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
		return;
	}
}

void PlayState::s_hitToDish() {
	TheGame::Instance()->addScore();
	AudioManager::Instance()->playEffect();
	std::cout << "Score : " << TheGame::Instance()->getScore() << std::endl;
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

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	SDL_ShowCursor(0);
	TheGame::Instance()->setScore(0);

	StateParser stateParser;
	stateParser.parseState("Resources/dish.xml", s_playID, &m_gameObjects, &m_textureIDList);

	for (int i = 0; i < 3; ++i) {
		dynamic_cast<Dish*>(m_gameObjects[i])->init();
	}
	TextureManager::Instance()->setAlpha("effect", 0);

	m_callbacks.push_back(s_hitToDish);
	m_callbacks.push_back(s_hitToDish);
	m_callbacks.push_back(s_hitToDish);

	setCallbacks(m_callbacks);

	//DishManager::Instance()->init(&m_gameObjects, &m_textureIDList);

	std::cout << "entering PlayState\n";

	return true;
}

void PlayState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		if (dynamic_cast<Dish*> (m_gameObjects[i])) {
			Dish* pDish = dynamic_cast<Dish*> (m_gameObjects[i]);
			pDish->setCallback(callbacks[pDish->getCallbackID()]);
		}
	}
}

bool PlayState::onExit() {
	GameState::onExit();
	SDL_ShowCursor(1);
	
	std::cout << "exiting PlayState\n";
	return true;
}