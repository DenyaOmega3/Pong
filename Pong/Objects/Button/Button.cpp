#include "Button.h"

Button::Button(const Text& text) : m_text(text)
{
}

Button::~Button()
{
}

void Button::render(SDL_Renderer* renderer)
{
	if (!m_text.m_texture)
		m_text.loadTexture(renderer);

	m_text.render(renderer);
}
