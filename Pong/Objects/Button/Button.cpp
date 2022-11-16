#include "Button.h"

Button::Button()
{
	m_font = TTF_OpenFont("Resource/Fonts/arial.ttf", 24);
	if (!m_font) {
		std::cout << "?";
	}
	m_surface = TTF_RenderText_Solid(m_font, "some button", { 255,255,255 });
	m_rectangle.w = 120;
	m_rectangle.h = 60;
}

Button::~Button()
{
	SDL_DestroyTexture(m_texture);
	SDL_FreeSurface(m_surface);
	TTF_CloseFont(m_font);
}

void Button::loadTexture(SDL_Renderer* renderer)
{
	m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
}

void Button::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, m_texture, nullptr, &m_rectangle);
}
