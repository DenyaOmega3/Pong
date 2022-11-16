#pragma once
#include "SDL.h"

class Scene
{

public:
	virtual void playScene(SDL_Renderer* render, SDL_Window* window) = 0;
};

