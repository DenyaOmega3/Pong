#pragma once
#include "SDL.h"

class Platform
{
	SDL_Rect m_rectangle;
	int m_platformSpeed;

public:
	Platform();

	void move();
	void updatePlatform(SDL_Window *window);
};

