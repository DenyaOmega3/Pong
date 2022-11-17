#include "Ball.h"

Ball::Ball()
{
	m_rectangle = SDL_Rect{ 859 / 2 - 5, 524 / 2 - 5, 2 * 5,2 * 5 };
	xMove = 1;
	yMove = 1;

	m_imaginaryX = m_rectangle.x;
	m_imaginaryY = m_rectangle.y;
}

Ball::Ball(const SDL_Rect& rectangle)
{
	m_rectangle = rectangle;
}

void Ball::move()
{
	m_imaginaryX += m_rectangle.w * 1.0 / 120 *xMove;
	m_imaginaryY += m_rectangle.h * 1.0 / 120 *yMove;

	m_rectangle.x = m_imaginaryX;
	m_rectangle.y = m_imaginaryY;

	if (m_rectangle.y + m_rectangle.h >= 524) {
		yMove = -1;
	}
	if (m_rectangle.x + m_rectangle.w >= 858) {
		xMove = -1;
	}
	if (m_rectangle.y <= 0) {
		yMove = 1;
	}
	if (m_rectangle.x <= 0) {
		xMove = 1;
	}
}

SDL_Rect& Ball::getRectangle()
{
	return m_rectangle;
}

void Ball::checkCollision(Platform& platform1, Platform& platform2)
{
	if (m_rectangle.y + m_rectangle.h >= platform1.getRectangle().y &&
		m_rectangle.y <= platform1.getRectangle().y + platform1.getRectangle().x)
		if (m_rectangle.x <= platform1.getRectangle().x + platform1.getRectangle().w)
			xMove = 1;

	if (m_rectangle.y + m_rectangle.h >= platform2.getRectangle().y &&
		m_rectangle.y <= platform2.getRectangle().y + platform2.getRectangle().x)
		if (m_rectangle.x + m_rectangle.w >= platform2.getRectangle().x)
			xMove = -1;
}

void Ball::checkPositionBot(Platform& botPlatform)
{
	if (m_rectangle.y >= botPlatform.getRectangle().y + botPlatform.getRectangle().h - 30) {
		botPlatform.moveDown();
	}

	if (m_rectangle.y + m_rectangle.h  <= botPlatform.getRectangle().y + 20) {
		botPlatform.moveUp();
	}
}
