#pragma once
#include "Scene.h"
#include "../Objects/Button/Button.h"

class MainMenu : public Scene {
	Button m_startGameButton;
public:
	MainMenu();
	void playScene(SDL_Renderer* render, SDL_Window* window) override;
};