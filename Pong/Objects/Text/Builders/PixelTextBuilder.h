#pragma once
#include "TextBuilder.h"

class PixelTextBuilder : public TextBuilder
{
public:
	PixelTextBuilder();
	~PixelTextBuilder();

	TextBuilder* buildFontName() override;

	TextBuilder* buildFont() override;
	TextBuilder* buildSurface() override;

	TextBuilder* buildDstRectangle() override;
	TextBuilder* buildDstRectangleColor() override;
};

