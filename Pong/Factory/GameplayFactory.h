#pragma once
#include "EngineFactory.h"

class GameplayFactory : public EngineFactory
{
public:
	Scene* createScene() override;
	EventHandler* createEventHandler() override;
};

