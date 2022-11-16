#include "SDL.h"
#undef main
#include <iostream>
#include <cassert>
#include "GameEngine.h"

/*
Pong components:
- Menu:
	- play
	- options
	- exit

- Options:
	- switch to fullscreen
	- keyboard settings

- Game

Main game contains:
- 2 platform, each one can be toggled
- ball
- score
- invisible wall
*/


/*
Menu creation

abstract Menu: clickable buttons, 
*/


/*
* Two problems to solve:
1. ResourceManager in order not to load constantly the same arial
2. SDL_CreateTextureFromSurface do once (check)
*/
int main() {
	assert(!SDL_Init(SDL_INIT_EVERYTHING),"SDL hasn't initialized");
	assert(!TTF_Init(), "TTF hasn't initialized");

	GameEngine engine;

	while (engine.isGameRunning()) {
		engine.renderScene();
		engine.handleEvents();
		engine.update();
	}

	SDL_Quit();
	TTF_Quit();

	/*
	fullscreen = false;
	int flags = 0;
	flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";

		window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
		if (window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(window, 100, 100);
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			isRunning = true;
		}

	}

	while (isRunning) {
		handleEvents();
		update();
		render();
	}

	//frees memory associated with renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	SDL_Quit();*/


	return 0;
}