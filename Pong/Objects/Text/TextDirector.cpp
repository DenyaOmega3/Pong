#include "TextDirector.h"

TextDirector::TextDirector()
{
}

void TextDirector::setBuilder(TextBuilder* builder)
{
	m_builder = builder;
}

void TextDirector::buildText()
{
	m_builder->buildFontName();
	m_builder->buildFont();
	m_builder->buildSurface();
	m_builder->buildDstRectangle();
}
