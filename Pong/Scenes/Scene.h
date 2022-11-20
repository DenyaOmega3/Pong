#pragma once
#include "SDL.h"

class Scene
{
public:
	virtual void renderScene(SDL_Renderer* renderer) = 0;
	virtual ~Scene();
};

