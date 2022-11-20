#include "Ball.h"

Ball::Ball() : BoxCollider()
{
	reset();
}

Ball::Ball(const SDL_Rect& rectangle)
{
	m_rectangle = rectangle;
}

void Ball::move()
{
	m_imaginaryX += m_rectangle.w * 1/15.0 * m_xDir;
	m_imaginaryY += m_rectangle.h * 1/15.0 * m_yDir;

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
	/*if (m_rectangle.y + m_rectangle.h >= platform1.getRectangle().y &&
		m_rectangle.y <= platform1.getRectangle().y + platform1.getRectangle().h)
		if (m_rectangle.x <= platform1.getRectangle().x + platform1.getRectangle().w)
			m_xDir = RIGHT;

	if (m_rectangle.y + m_rectangle.h >= platform2.getRectangle().y &&
		m_rectangle.y <= platform2.getRectangle().y + platform2.getRectangle().h)
		if (m_rectangle.x + m_rectangle.w >= platform2.getRectangle().x)
			m_xDir = LEFT;*/

	m_isCollidingWithPlatform += isColliding(platform.getRectangle());
}

void Ball::checkPositionBot(Platform& botPlatform)
{
	int random = rand()%100; //probability not to move

	if (random >= 80) {
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
	m_rectangle = SDL_Rect{ 859 / 2 - 5, 524 / 2 - 5, 2 * 5,2 * 5 };
	m_xDir = STOPH;
	m_yDir = STOPV;

	m_isCollidingWithPlatform = false;
	m_isOutOfScreen = FALSE;

	m_imaginaryX = m_rectangle.x;
	m_imaginaryY = m_rectangle.y;
}
