#pragma once
#include "SDL.h"
//#include "../../GameEngine.h"

class Platform
{
	SDL_Rect m_rectangle;
	static int m_platformSpeed;

public:
	Platform();
	Platform(const SDL_Rect& rectangle);

	void moveUp();
	void moveDown();

	SDL_Rect& getRectangle();
};

