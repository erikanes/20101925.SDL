#include "GameOverState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "StateParser.h"
#include "MenuButton.h"
#include "LetterManager.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	TheTextureManager::Instance()->draw(LetterManager::Instance()->getLetter(), 200, 200, 100, 100, TheGame::Instance()->getRenderer());
}

bool GameOverState::onEnter() {
	StateParser stateParser;
	stateParser.parseState("Resources/dish.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);

	LetterManager::Instance()->createLetter(TheGame::Instance()->getScore(), TheGame::Instance()->getRenderer());

	m_callbacks.push_back(s_gameOverToMain);

	setCallbacks(m_callbacks);

	std::cout << "entering GameOverState" << std::endl;
	return true;
}

bool GameOverState::onExit() {
	GameState::onExit();

	std::cout << "exiting GameOverState" << std::endl;
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback> &callbacks) {
	for (int i = 0; i<m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton *pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}