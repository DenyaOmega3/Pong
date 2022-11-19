#include "Text.h"

const std::string Text::path = "Resource/Fonts/";

Text::Text() : m_xPosition(0), m_yPosition(0), m_displayWithRectangle(false)
{
	m_fontSDL = nullptr;
	m_surface = nullptr;
	m_texture = nullptr;
}

Text::Text(const std::string& name, int size, const SDL_Color &color, 
	const std::string& text, int xPosition, int  yPosition, bool displayWithRectangle,
	const SDL_Color& dstRectColor)
	: m_fontName(name), m_size(size), m_textColor(color), m_text(text), m_xPosition(xPosition),
	m_yPosition(yPosition), m_displayWithRectangle(displayWithRectangle), m_dstRectColor(dstRectColor)
{
	loadFont();
	loadSurface();
	loadDstRectangle();

	m_texture = nullptr;
}

Text::~Text()
{
	SDL_DestroyTexture(m_texture);
	SDL_FreeSurface(m_surface);
	TTF_CloseFont(m_fontSDL);
}

void Text::setFontName(const std::string& fontName)
{
	m_fontName = fontName;
}

void Text::setSize(int size)
{
	m_size = size;
}

void Text::setTextColor(const SDL_Color& color)
{
	m_textColor = color;
}

void Text::setPositionX(int xPosition)
{
	m_xPosition = xPosition;
}

void Text::setPositionY(int yPosition)
{
	m_yPosition = yPosition;
}

void Text::setTextContent(const std::string& text)
{
	m_text = text;
}

void Text::loadFont()
{
	if (m_fontSDL)
		TTF_CloseFont(m_fontSDL);
	m_fontSDL = TTF_OpenFont((path+m_fontName).c_str(), m_size);
	assert(m_fontSDL, "Couldn't load font");
}

void Text::loadSurface()
{
	if (m_surface)
		SDL_FreeSurface(m_surface);
	m_surface = TTF_RenderText_Solid(m_fontSDL, m_text.c_str(), m_textColor);
	assert(m_surface, "Couldn't load surface for text");
}

void Text::loadTexture(SDL_Renderer* renderer)
{
	if (m_texture == nullptr)
		m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
}

void Text::loadDstRectangle() {
	m_dstRectangle = { m_xPosition- m_surface->w/2, m_yPosition, m_surface->w, m_surface->h };
}

void Text::render(SDL_Renderer* renderer)
{
	if (m_displayWithRectangle) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &m_dstRectangle);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderCopy(renderer, m_texture, nullptr, &m_dstRectangle);
}

const std::string& Text::getTextContent() {
	return m_text;
}

SDL_Rect& Text::getDstRectangle()
{
	return m_dstRectangle;
}

void Text::setDstRectangleColor(const SDL_Color& dstRectColor)
{
	m_dstRectColor = dstRectColor;
}

void Text::setDisplayWithRectangle()
{
	m_displayWithRectangle = true;
}
