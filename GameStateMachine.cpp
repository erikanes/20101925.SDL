#include "GameStateMachine.h"
#include "GameState.h"
//#include "StatePool.h"

void GameStateMachine::pushState(GameState* pState) {
	m_gameStates.push_back(pState);
	//StatePool::Instance()->push(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->onExit()) {
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState) {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->getStateID() == pState->getStateID()) {
			return;
		}
		if (m_gameStates.back()->onExit()) {
			//delete m_gameStates.back();
			m_gameStates.pop_back();
			//popState();
		}
	}
	pushState(pState);
}

void GameStateMachine::update() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
}