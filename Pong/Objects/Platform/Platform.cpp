#include "Platform.h"

int Platform::m_platformSpeed = 20;

Platform::Platform() : BoxCollider()
{
	int maxHeight = 524;

	int marginX = 60;
	int rectWidth = 10, rectHeight = 40;
	m_rectangle = SDL_Rect{ marginX, maxHeight / 2 - rectHeight / 2, rectWidth, rectHeight };
}

Platform::Platform(const SDL_Rect& rectangle)
{
	m_rectangle = rectangle;
}

void Platform::moveUp()
{
	m_rectangle.y -= m_platformSpeed;
	if (m_rectangle.y < 0)
		m_rectangle.y = 0;
}

void Platform::moveDown()
{
	int maxHeight = 524;
	
	m_rectangle.y += m_platformSpeed;
	if (m_rectangle.y+m_rectangle.h > maxHeight)
		m_rectangle.y = maxHeight - m_rectangle.h;
}

SDL_Rect& Platform::getRectangle()
{
	return m_rectangle;
}
