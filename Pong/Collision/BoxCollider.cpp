#include "BoxCollider.h"

BoxCollider::BoxCollider()
{

}

BoxCollider::BoxCollider(const SDL_Rect& rectangle)
{
	m_rectangle = rectangle;
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

void BoxCollider::setRectangle(SDL_Rect& rectnangle)
{
	m_rectangle = rectnangle;
}
