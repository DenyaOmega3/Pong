#pragma once
#include "EventHandler.h"
class MainMenuEvent : public EventHandler
{
public:
	void handleEvents(Scene* currentScene) override;
};

