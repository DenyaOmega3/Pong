#pragma once
#include "Scene.h"
#include "../Objects/Button/Button.h"

class MainMenu : public Scene {
	Text m_textStartGameButton;
	Button m_startGameButton;

	Text m_textExitButton;
	Button m_exitButton;
public:
	MainMenu();
	void playScene(SDL_Renderer* renderer, SDL_Window* window) override;
};