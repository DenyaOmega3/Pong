#pragma once
#include "TextBuilder.h"

class ArialTextBuilder : public TextBuilder
{
public:
	ArialTextBuilder();
	~ArialTextBuilder();

	TextBuilder* buildFontName() override;

	TextBuilder* buildFont() override;
	TextBuilder* buildSurface() override;

	TextBuilder* buildDstRectangle() override;
	TextBuilder* buildDstRectangleColor() override;
};

class 
{
};

