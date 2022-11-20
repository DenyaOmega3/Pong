#pragma once
#include "EngineFactory.h"

class MatchFactory : public EngineFactory
{
public:
	Scene* createScene() override;
	EventHandler* createEventHandler() override;
};

