#pragma once
#include "ArialTextBuilder.h"

class ArialTextWithRectangleBuilder : public ArialTextBuilder
{
public:
	TextBuilder* buildDstRectangleColor() override;
};

