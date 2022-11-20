#include "Platform.h"
int Platform::platformWidth = 10;
int Platform::platformHeight = 40;
int Platform::m_platformSpeed = 20;
int Platform::horizontalMargin = 60;


Platform::Platform() : BoxCollider()
{
	m_rectangle = SDL_Rect{ horizontalMargin, windowHeight / 2 - platformHeight / 2, platformWidth, platformHeight };
}

Platform::Platform(const SDL_Rect& rectangle) : BoxCollider(rectangle)
{
}

void Platform::moveUp()
{
	m_rectangle.y -= m_platformSpeed;
	if (m_rectangle.y < 0)
		m_rectangle.y = 0;
}

void Platform::moveDown()
{
	m_rectangle.y += m_platformSpeed;
	if (m_rectangle.y+m_rectangle.h > windowHeight)
		m_rectangle.y = windowHeight - m_rectangle.h;
}

SDL_Rect& Platform::getRectangle()
{
	return m_rectangle;
}

void Platform::reset()
{
	int marginX = 60;
	m_rectangle = SDL_Rect{ horizontalMargin, windowHeight / 2 - platformWidth / 2, platformWidth, platformHeight };
}
