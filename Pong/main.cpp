#include "SDL.h"
#undef main
#include <time.h>
#include "GameEngine.h"

int main() {
	srand(time(nullptr));
	GameEngine* engine = GameEngine::getInstance();

	while (engine->isGameRunning()) {
		engine->loadDeltaTime();
		engine->renderScene();
		engine->handleEvents();
	}

	delete engine;

	return 0;
}