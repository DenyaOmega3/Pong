#include "ArialTextBuilder.h"
ArialTextBuilder::ArialTextBuilder()
{
    buildingText = new Text();
}

ArialTextBuilder::~ArialTextBuilder()
{
    //delete buildingText;
}

TextBuilder* ArialTextBuilder::buildFontName()
{
    buildingText->setFontName("arial.ttf");
    return this;
}

TextBuilder* ArialTextBuilder::buildFont()
{
    buildingText->loadFont();
    return this;
}

TextBuilder* ArialTextBuilder::buildSurface()
{
    buildingText->loadSurface();
    return this;
}

TextBuilder* ArialTextBuilder::buildDstRectangle()
{
    buildingText->loadDstRectangle();
    return this;
}

TextBuilder* ArialTextBuilder::buildDstRectangleColor()
{
    return this;
}