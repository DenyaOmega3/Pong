#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>

class Button
{
	SDL_Rect m_rectangle;
	TTF_Font* m_font;
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;

public:
	Button();
	~Button();

	void loadTexture(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer);
};

