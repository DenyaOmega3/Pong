#pragma once
#include "SDL.h"

class Scene
{
public:
	virtual void playScene(SDL_Renderer* renderer, SDL_Window* window) = 0;
	virtual ~Scene();
};

