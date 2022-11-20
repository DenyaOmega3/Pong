#pragma once
#include "SDL.h"

class BoxCollider
{
protected:
	SDL_Rect m_rectangle;
public:
	BoxCollider();
	BoxCollider(const SDL_Rect& rectangle);
	bool isColliding(SDL_Rect &anotherCollider);

	SDL_Rect& getRectangle();
	void setRectangle(SDL_Rect &rectnangle);
};

