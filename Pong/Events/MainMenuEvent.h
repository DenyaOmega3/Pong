#pragma once
#include "EventHandler.h"
#include "../Scenes/MainMenu.h"

class MainMenuEvent : public EventHandler
{
public:
	void handleEvents(Scene* currentScene) override;

	bool checkIfPressed(int xMouse, int yMouse, const SDL_Rect& rectangle);
};

