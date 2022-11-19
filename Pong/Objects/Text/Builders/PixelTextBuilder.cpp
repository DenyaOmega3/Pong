#include "PixelTextBuilder.h"

PixelTextBuilder::PixelTextBuilder()
{
    buildingText = new Text();
}

PixelTextBuilder::~PixelTextBuilder()
{
    //delete buildingText;
}

TextBuilder* PixelTextBuilder::buildFontName()
{
    buildingText->setFontName("PublicPixel.ttf");
    return this;
}

TextBuilder* PixelTextBuilder::buildFont()
{
    buildingText->loadFont();
    return this;
}

TextBuilder* PixelTextBuilder::buildSurface()
{
    buildingText->loadSurface();
    return this;
}

TextBuilder* PixelTextBuilder::buildDstRectangle()
{
    buildingText->loadDstRectangle();
    return this;
}

TextBuilder* PixelTextBuilder::buildDstRectangleColor()
{
    return this;
}
