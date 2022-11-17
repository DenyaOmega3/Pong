#pragma once
#include "EventHandler.h"
#include <iostream>
#include "../Scenes/GameScene.h"

class GameSceneEvent : public EventHandler
{

public:
	void handleEvents(Scene* currentScene) override;

	//Event descriptions
	void movePlatformDown(SDL_Rect& platform);
	void movePlatformUp(SDL_Rect& platform);

	void moveBall(SDL_Rect &ball);
};

