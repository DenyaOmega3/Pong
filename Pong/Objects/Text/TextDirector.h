#pragma once
#include "Builders/TextBuilder.h"

class TextDirector
{
	TextBuilder* m_builder;

public:
	TextDirector();

	void setBuilder(TextBuilder* builder);
	void buildText();
};

