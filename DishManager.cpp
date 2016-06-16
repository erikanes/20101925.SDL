//#include "DishManager.h"
//#include "Dish.h"
//#include <string>
//
//DishManager* DishManager::mInstance = 0;
//
//DishManager::DishManager() : SIZE(3) {
//	puts("DishManager 积己");
//}
//
//DishManager::~DishManager() {
//	if (mDish != NULL) {
//		delete[] mDish;
//		mDish = NULL;
//	}
//	puts("DishManager 昏力");
//}
//
//void DishManager::init() {
//	mDish = new Dish[SIZE];
//	std::string id[3] = { "dish1", "dish2", "dish3" };
//
//	for (int i = 0; i < SIZE; ++i) {
//		//mDish[i].init(id[i]);
//	}
//}
//
//void DishManager::update(SDL_Renderer* _renderer) {
//	//for (int i = 0; i < SIZE; ++i) {
//	//	TextureManager::Instance()->setAlpha(mDish[i].getTexture(), mDish[i].getAlpha());
//
//	//	TextureManager::Instance()
//	//		->draw(mDish[i].getTexture(), mDish[i].getPosition().x, mDish[i].getPosition().y,
//	//		mDish[i].getDiameter(), mDish[i].getDiameter(), _renderer);
//	//}
//}
//
//Dish* DishManager::getDish(int _idx) const {
//	return &mDish[_idx];
//}

#include "DishManager.h"
#include "Dish.h"
#include "GameObjectFactory.h"
#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include <iostream>
#include <random>
#include <functional>

DishManager* DishManager::mInstance = 0;

DishManager::DishManager() : SIZE(3) {
	puts("DishManager 积己");
}

DishManager::~DishManager() {
	//while (!mDish.empty()) {
	//	if (mDish.back() != NULL) {
	//		Dish* dish = mDish.back();
	//		mDish.pop_back();
	//		delete dish;
	//		dish = NULL;
	//	}
	//}
	puts("DishManager 昏力");
}

void DishManager::init(std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs) {
	std::string textureID[3] = { "dish1", "dish2", "dish3" };

	for (int i = 0; i < SIZE; ++i) {
		Dish* dish = dynamic_cast<Dish*>(TheGameObjectFactory::Instance()->create("Dish"));
		dish->load(new LoaderParams(100, 100, 100, 100, textureID[i], 0));
		dish->init();
		pTextureIDs->push_back(textureID[i]);
		pObjects->push_back(dish);
	}
}

//void DishManager::update() {
//	for (int i = 0; i < SIZE; ++i) {
//		mDish[i]->update();
//	}
//}
//
//void DishManager::draw() {
//	for (int i = 0; i < SIZE; ++i) {
//		mDish[i]->draw();
//	}
//}
//
//Dish* DishManager::getDish(int _idx) const {
//	return mDish[_idx];
//}