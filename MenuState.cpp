#include "MenuState.h"
#include "GameObject.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit() {
	//for (int i = 0; i < m_gameObjects.size(); ++i) {	
	//	//m_gameObjects[i]->clean();
	//	delete m_gameObjects[i];
	//	m_gameObjects[i] = NULL;
	//}
	//m_gameObjects.clear();
	//TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	//TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	//std::cout << "exiting MenuState\n";
	//return true;
	return true;
}

void MenuState::s_menuToPlay() {
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
	//TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

void MenuState::s_exitFromMenu() {
	TheGame::Instance()->quit();
	std::cout << "Exit button clicked\n";
}