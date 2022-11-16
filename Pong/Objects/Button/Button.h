#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include "../Text/Text.h"

class Button
{
	Text m_text;

public:
	Button(const Text& text);
	~Button();

	void render(SDL_Renderer* renderer);
};

