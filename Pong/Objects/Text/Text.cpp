#include "Text.h"

Text::Text(const std::string& name, int size, const SDL_Color &color, const std::string& text, int xPosition, int  yPosition)
	: m_fontName(name), m_size(size), m_color(color), m_text(text), m_xPosition(xPosition), m_yPosition(yPosition)
{
	std::string path = "Resource/Fonts/" + m_fontName;
	m_fontSDL = TTF_OpenFont(path.c_str(), m_size);
	assert(m_fontSDL, "Couldn't load font");

	m_surface = TTF_RenderText_Solid(m_fontSDL, m_text.c_str(), m_color);
	assert(m_surface, "Couldn't load surface for text");

	m_dstRectangle = { m_xPosition,m_yPosition, m_surface->w, m_surface->h };

	m_texture = nullptr;
}

void Text::loadTexture(SDL_Renderer* renderer)
{
	m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
}

void Text::render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, m_texture, nullptr, &m_dstRectangle);
}

Text::~Text()
{
	SDL_DestroyTexture(m_texture);
	SDL_FreeSurface(m_surface);
	TTF_CloseFont(m_fontSDL);
}
