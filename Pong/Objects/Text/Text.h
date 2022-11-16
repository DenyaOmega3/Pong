#pragma once
#include <string>
#include <cassert>
#include "SDL_ttf.h"

class Text
{
	std::string m_fontName;
	int m_size;
	SDL_Color m_color;
	int m_xPosition;
	int m_yPosition;

	std::string m_text;

	TTF_Font* m_fontSDL;
	SDL_Surface* m_surface;
	
	SDL_Rect m_dstRectangle;

public:
	Text(const std::string& name, int size, const SDL_Color& color, const std::string& text, int xPosition, int  yPosition);

	void loadTexture(SDL_Renderer *renderer);
	void render(SDL_Renderer* renderer);

	~Text();

	SDL_Texture* m_texture;
};

