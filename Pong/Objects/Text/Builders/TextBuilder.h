#pragma once
#include "../Text.h"

class TextBuilder
{
protected:
	Text* buildingText;
public:
	virtual TextBuilder* buildSize(int size);
	virtual TextBuilder* buildColor(const SDL_Color& color);
	virtual TextBuilder* buildTextContent(const std::string& text);
	virtual TextBuilder* buildPosition(int x, int y);

	virtual TextBuilder* buildFontName() = 0;
	virtual TextBuilder* buildFont() = 0;
	virtual TextBuilder* buildSurface() = 0;

	virtual TextBuilder* buildDstRectangle() = 0;
	virtual TextBuilder* buildDstRectangleColor() = 0;

	Text* getBuiltText();
};

