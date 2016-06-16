//#include "Dish.h"
//#include "TextureManager.h"
//#include <random>
//#include <ctime>
//#include <functional>
//
//int createRandom(int min, int max);
//
//Dish::Dish() {
//	puts("Dish 积己");
//}
//
//Dish::~Dish() {
//	puts("Dish 昏力");
//}
//
//void Dish::init(std::string _id) {
//	mDiameter = 170;
//	reset();
//	//mTexture = TextureManager::Instance()->get(_id);
//}
//
//Position Dish::getPosition() const {
//	return mPosition;
//}
//
//int Dish::getDiameter() const {
//	return mDiameter;
//}
//
//SDL_Texture* Dish::getTexture() const {
//	return mTexture;
//}
//
//int Dish::getAlpha() {
//	return mAlpha = mAlpha<255 ? mAlpha+15:255;
//}
//
//void Dish::reset() {
//	mPosition.x = createRandom(0, SCREEN_WIDTH - mDiameter);
//	mPosition.y = createRandom(0, SCREEN_HEIGHT - mDiameter);
//
//	mAlpha = 0;
//}
//
//
//int createRandom(int min, int max)
//{
//	std::tr1::random_device rd;
//	std::tr1::mt19937 engine(rd());
//	std::tr1::uniform_int_distribution<int> distribution(min, max);
//	auto generator = std::tr1::bind(distribution, engine);
//
//	return generator();
//}

#include "Dish.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameOverState.h"
#include <random>
#include <functional>
#include <time.h>
#include <iostream>
#include <cmath>

Dish::Dish() : SDLGameObject() {}

void Dish::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_bReleased = true;
}

void Dish::draw() {
	//SDLGameObject::draw();
	TextureManager::Instance()->draw(m_textureID, m_position.getX(), m_position.getY(), m_diameter, m_diameter,
		TheGame::Instance()->getRenderer());
}

void Dish::update() {
	if (m_alpha < 255) {
		m_alpha += 15;
	}
	TheTextureManager::Instance()->setAlpha(m_textureID, m_alpha);

	//if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT) && m_bReleased) {
	//	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	//	float x = getPosition().getX();
	//	float y = getPosition().getY();

	//	float distance = std::powf(pMousePos->getX() - (x + (m_diameter / 2.0f)), 2.0f)
	//		+ std::powf(pMousePos->getY() - (y + (m_diameter / 2.0f)), 2.0f);

	//	if (distance <= std::powf(m_diameter / 2.0f, 2.0f)) {
	//		m_callback();
	//		init();
	//	}
	//	else {
	//		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
	//	}
	//}
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

void Dish::clean() {
	SDLGameObject::clean();
}

void Dish::init() {
	m_alpha = 0;
	m_bReleased = true;

	int rPosX = Dish::createRandom(0, 500);
	int rPosY = Dish::createRandom(0, 400);
	int rDiameter = Dish::createRandom(170, 170);
	
	m_position.setX(rPosX);
	m_position.setY(rPosY);
	m_diameter = rDiameter;

	std::cout << m_textureID << "积己. x=" << m_position.getX() << " y=" << m_position.getY() << " diameter = " << m_diameter << std::endl;
}

int Dish::createRandom(int min, int max)
{
	std::tr1::random_device rd;
	std::tr1::mt19937 engine(rd());
	std::tr1::uniform_int_distribution<int> distribution(min, max);
	auto generator = std::tr1::bind(distribution, engine);

	return generator();
}