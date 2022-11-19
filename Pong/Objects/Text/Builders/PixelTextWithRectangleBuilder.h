#pragma once
#include "PixelTextBuilder.h"
class PixelTextWithRectangleBuilder : public PixelTextBuilder
{
public:
	TextBuilder* buildDstRectangleColor() override;
};

