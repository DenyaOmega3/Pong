#pragma once
#include "../Scenes/MatchScene.h"
#include "../Events/MatchEvent.h"
#include "../Scenes/MainMenu.h"
#include "../Events/MainMenuEvent.h"

class EngineFactory
{
public:
	virtual Scene* createScene() = 0;
	virtual EventHandler* createEventHandler() = 0;
};

