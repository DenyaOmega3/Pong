#include "TextBuilder.h"

Text* TextBuilder::getBuiltText()
{
    return buildingText;
}

TextBuilder* TextBuilder::buildSize(int size)
{
    buildingText->setSize(size);
    return this;
}

TextBuilder* TextBuilder::buildColor(const SDL_Color& color)
{
    buildingText->setTextColor(color);
    return this;
}

TextBuilder* TextBuilder::buildTextContent(const std::string& text)
{
    buildingText->setTextContent(text);
    return this;
}

TextBuilder* TextBuilder::buildPosition(int x, int y)
{
    buildingText->setPositionX(x);
    buildingText->setPositionY(y);
    return nullptr;
}