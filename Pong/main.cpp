#include "SDL.h"
#undef main
#include <iostream>
#include "GameEngine.h"

int main() {
	GameEngine* engine = GameEngine::getInstance();

	while (engine->isGameRunning()) {
		engine->renderScene();
		engine->handleEvents();
		engine->update();
	}

	delete engine;
	return 0;
}