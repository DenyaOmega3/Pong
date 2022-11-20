#pragma once
#include "SDL.h"
#include "../Platform/Platform.h"
#include <iostream>
#include "../../preferences.h"

enum xDirection {LEFT = -1, STOPH = 0, RIGHT = 1};
enum yDirection { UP = -1, STOPV = 0, DOWN = 1 };
enum OutOfScreen {TRUE_LEFT = -1, FALSE = 0, TRUE_RIGHT = 1};

class Ball : public BoxCollider
{
	xDirection m_xDir;
	yDirection m_yDir;

	bool m_isCollidingWithPlatform;

	float m_imaginaryX;
	float m_imaginaryY;
	OutOfScreen m_isOutOfScreen;

	static int m_ballSpeed;

public:	
	Ball();
	Ball(const SDL_Rect& rectangle);

	void move(float dt);
	void stopMoving();
	void startMoving();

	SDL_Rect& getRectangle();

	void checkCollision(Platform& platform);

	void checkPositionBot(Platform& botPlatform);
	void changeDirection();

	OutOfScreen isOutOfScreen();

	void reset();
};

