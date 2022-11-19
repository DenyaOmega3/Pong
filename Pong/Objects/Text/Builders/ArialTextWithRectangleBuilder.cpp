#include "ArialTextWithRectangleBuilder.h"

TextBuilder* ArialTextWithRectangleBuilder::buildDstRectangleColor()
{
	buildingText->setDstRectangleColor({ 255,0,0 });
	buildingText->setDisplayWithRectangle();
	return this;
}