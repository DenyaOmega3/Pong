#pragma once
#include "SDL.h"
#include "../Platform/Platform.h"
#include <iostream>

enum xDirection {LEFT = -1, STOPH = 0, RIGHT = 1};
enum yDirection { UP = -1, STOPV = 0, DOWN = 1 };

class Ball : public BoxCollider
{
	xDirection m_xDir;
	yDirection m_yDir;

	bool isCollidingWithPlatform;

	float m_imaginaryX;
	float m_imaginaryY;

public:
	Ball();
	Ball(const SDL_Rect& rectangle);

	void move();

	SDL_Rect& getRectangle();

	void checkCollision(Platform& platform);

	void checkPositionBot(Platform& botPlatform);
	void changeDirection();
};

