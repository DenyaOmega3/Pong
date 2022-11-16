#pragma once
#include "SDL_ttf.h"

class Text
{
	TTF_Font* m_font;
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;

public:
	Text();
	~Text();
};

