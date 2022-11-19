#pragma once
#include "EngineFactory.h"

class MainMenuFactory : public EngineFactory
{
public:
	Scene* createScene() override;
	EventHandler* createEventHandler() override;
};

