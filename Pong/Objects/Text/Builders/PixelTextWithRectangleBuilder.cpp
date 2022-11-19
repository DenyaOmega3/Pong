#include "PixelTextWithRectangleBuilder.h"

TextBuilder* PixelTextWithRectangleBuilder::buildDstRectangleColor()
{
	buildingText->setDstRectangleColor({255,0,0});
	buildingText->setDisplayWithRectangle();
	return this;
}
