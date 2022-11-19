#pragma once
#include "SDL.h"

class BoxCollider
{
protected:
	SDL_Rect m_rectangle;
public:
	BoxCollider();
	bool isColliding(SDL_Rect &anotherCollider);

	SDL_Rect& getRectangle();
};

