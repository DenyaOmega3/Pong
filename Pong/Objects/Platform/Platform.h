#pragma once
#include "SDL.h"
#include "../../Collision/BoxCollider.h"
//#include "../../GameEngine.h"

class Platform : public BoxCollider
{
	static int m_platformSpeed;

public:
	Platform();
	Platform(const SDL_Rect& rectangle);

	void moveUp();
	void moveDown();

	SDL_Rect& getRectangle();
};

