#include <iostream>
#include "Game.h"
#include "GeneralData.h"

int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;
	Uint32 frameStart, frameTime;	

	if (TheGame::Instance()->init("Dish Crash", 100, 100, 640, 480, false)) {
		while (TheGame::Instance()->running()) {
			frameStart = SDL_GetTicks();
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else {
		std::cout << "game init failure  - " << SDL_GetError() << std::endl;
		return -1;
	}
	std::cout << "game closing\n";
	TheGame::Instance()->clean();

	//Game* game = NULL;
	//game = new Game();
	//game->init("Dish Crash", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT);

	//while (game->running()) {
	//	game->handleEvents();
	//	game->update();
	//	game->render();
	//}

	//game->clean();
	//if (game != NULL) {
	//	delete game;
	//	game = NULL;
	//}

	return 0;
}