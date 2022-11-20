#include "SDL.h"
#undef main
#include <iostream>
#include <time.h>
#include "GameEngine.h"

int main() {
	srand(time(nullptr));
	GameEngine* engine = GameEngine::getInstance();

	while (engine->isGameRunning()) {
		engine->renderScene();
		engine->handleEvents();
	}

	delete engine;
	return 0;
}