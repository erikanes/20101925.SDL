#include "MainMenuState.h"
#include "StateParser.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "Game.h"
#include "GameObject.h"

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->update();
	}
}
void MainMenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->draw();
	}
}

bool MainMenuState::onEnter() {
	StateParser stateParser;
	stateParser.parseState("Resources/dish.xml", s_menuID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	//m_callbacks.push_back(s_exitFromMenu);

	setCallbacks(m_callbacks);
	std::cout << "entering MenuState\n";

	return true;
}

bool MainMenuState::onExit() {
	GameState::onExit();

	return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		if (dynamic_cast<MenuButton*> (m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*> (m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void MainMenuState::s_menuToPlay() {
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu() {
	TheGame::Instance()->quit();
	std::cout << "Exit button clicked\n";
}