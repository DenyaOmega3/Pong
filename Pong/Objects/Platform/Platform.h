#pragma once
#include "SDL.h"
#include "../../Collision/BoxCollider.h"
#include "../../preferences.h"

class Platform : public BoxCollider
{
	static int m_platformSpeed;
	static int platformWidth;
	static int platformHeight;
	static int horizontalMargin;

public:
	Platform();
	Platform(const SDL_Rect& rectangle);

	void moveUp();
	void moveDown();

	SDL_Rect& getRectangle();

	void reset();
};

