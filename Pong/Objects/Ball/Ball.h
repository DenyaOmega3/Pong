#pragma once
#include "SDL.h"
#include "../Platform/Platform.h"

class Ball
{
	SDL_Rect m_rectangle;
	int xMove;
	int yMove;

	float m_imaginaryX;
	float m_imaginaryY;

public:
	Ball();
	Ball(const SDL_Rect& rectangle);

	void move();

	SDL_Rect& getRectangle();

	void checkCollision(Platform& platform1, Platform& platform2);

	void checkPositionBot(Platform& botPlatform);
};

