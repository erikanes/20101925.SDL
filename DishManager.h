//#ifndef _DISH_MANAGER_H_
//#define _DISH_MANAGER_H_
//
//#include <SDL.h>
//#include "Dish.h"
//#include "TextureManager.h"
//
//class DishManager {
//public:
//	static DishManager* instance() {
//		if (mInstance == 0) {
//			mInstance = new DishManager();
//			mInstance->init();
//		}
//		return mInstance;
//	}
//	DishManager();
//	~DishManager();
//
//	void init();
//	void update(SDL_Renderer* _renderer);
//	Dish* getDish(int idx) const;
//
//	const int SIZE;
//
//private:
//	static DishManager* mInstance;
//	Dish* mDish;
//};
//
//#endif

#ifndef _DISH_MANAGER_H_
#define _DISH_MANAGER_H_

#include <vector>
#include <string>

class GameObject;
class DishManager {
public:
	static DishManager* Instance() {
		if (mInstance == 0) {
			mInstance = new DishManager();
		}
		return mInstance;
	}
	DishManager();
	~DishManager();

	void init(std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);
	//void update();
	//void draw();
	//Dish* getDish(int idx) const;

	const int SIZE;

private:
	static DishManager* mInstance;
};

#endif