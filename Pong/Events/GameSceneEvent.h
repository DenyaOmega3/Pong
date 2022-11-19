#pragma once
#include "EventHandler.h"
#include <iostream>
#include "../Scenes/GameScene.h"

class GameSceneEvent : public EventHandler
{

public:
	void handleEvents(Scene* currentScene) override;
	void update(Scene* currentScene);
};

