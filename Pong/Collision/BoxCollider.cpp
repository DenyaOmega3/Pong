#include "BoxCollider.h"

BoxCollider::BoxCollider()
{
}

bool BoxCollider::isColliding(SDL_Rect& anotherCollider)
{
	return (m_rectangle.x < anotherCollider.x + anotherCollider.w &&
		m_rectangle.x + m_rectangle.w > anotherCollider.x &&
		m_rectangle.y < anotherCollider.y + anotherCollider.h &&
		m_rectangle.h + m_rectangle.y > anotherCollider.y);
}

SDL_Rect& BoxCollider::getRectangle()
{
	return m_rectangle;
}
