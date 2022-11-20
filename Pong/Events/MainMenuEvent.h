#pragma once
#include "EventHandler.h"
#include "../Scenes/MainMenu.h"

class MainMenuEvent : public EventHandler
{
	MainMenu* m_scene;
public:
	void handleEvents() override;

	void setScene(Scene* scene) override;

	bool checkIfPressed(int xMouse, int yMouse, const SDL_Rect& rectangle);
};

