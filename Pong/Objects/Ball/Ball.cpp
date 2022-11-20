#include "Ball.h"

int ballWidth = 10;
int ballHeight = 10;
int Ball::m_ballSpeed = 300;

Ball::Ball() : 
	BoxCollider()
{
	reset();
}

Ball::Ball(const SDL_Rect& rectangle) : BoxCollider(rectangle)
{
	m_imaginaryX = m_rectangle.x;
	m_imaginaryY = m_rectangle.y;
	m_xDir = STOPH;
	m_yDir = STOPV;

	m_isCollidingWithPlatform = false;
	m_isOutOfScreen = FALSE;
}

void Ball::move(float dt)
{
	m_imaginaryX += m_ballSpeed * m_xDir * dt;
	m_imaginaryY += m_ballSpeed * m_yDir * dt;

	m_rectangle.x = m_imaginaryX;
	m_rectangle.y = m_imaginaryY;

	changeDirection();
}

void Ball::stopMoving()
{
	m_xDir = STOPH;
	m_yDir = STOPV;
}

void Ball::startMoving()
{
	m_xDir = RIGHT;
	m_yDir = UP;
}

SDL_Rect& Ball::getRectangle()
{
	return m_rectangle;
}

void Ball::checkCollision(Platform& platform)
{
	m_isCollidingWithPlatform += isColliding(platform.getRectangle());
}

void Ball::checkPositionBot(Platform& botPlatform)
{
	//trying to imitate that bot will miss somewhen
	int random = rand()%100;

	if (random >= 98) {
		if (m_rectangle.y >= botPlatform.getRectangle().y + botPlatform.getRectangle().h - 30) {
			botPlatform.moveDown();
		}

		if (m_rectangle.y + m_rectangle.h  <= botPlatform.getRectangle().y + 20) {
			botPlatform.moveUp();
		}
	}
}

void Ball::changeDirection()
{
	if (m_rectangle.y + m_rectangle.h >= 524) {
		m_yDir = UP;
	}
	if (m_rectangle.y <= 0) {
		m_yDir = DOWN;
	}
	if (m_rectangle.x + m_rectangle.w >= 858) {
		m_isOutOfScreen = TRUE_RIGHT;
		stopMoving();
	}
	if (m_rectangle.x <= 0) {
		m_isOutOfScreen = TRUE_LEFT;
		stopMoving();
	}
	if (m_isCollidingWithPlatform) {
		m_xDir = static_cast<xDirection>((-1)*m_xDir);
		m_isCollidingWithPlatform = false;
	}
}

OutOfScreen Ball::isOutOfScreen()
{
	return m_isOutOfScreen;
}

void Ball::reset()
{
	m_rectangle = SDL_Rect{ (windowWidth) / 2 - 5, windowHeight / 2 - ballHeight / 2, ballWidth,ballHeight };
	m_xDir = STOPH;
	m_yDir = STOPV;

	m_isCollidingWithPlatform = false;
	m_isOutOfScreen = FALSE;

	m_imaginaryX = m_rectangle.x;
	m_imaginaryY = m_rectangle.y;
}
