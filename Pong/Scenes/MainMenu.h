#pragma once
#include "Scene.h"
#include "../Objects/Text/Builders/PixelTextWithRectangleBuilder.h"
#include "../Objects/Text/Builders/ArialTextWithRectangleBuilder.h"
#include "../Objects/Text/TextDirector.h"

class MainMenu : public Scene {
	Text *m_title;
	Text *m_textStartGame;
	Text* m_textExitGame;

public:
	MainMenu();
	~MainMenu();
	void playScene(SDL_Renderer* renderer, SDL_Window* window) override;

	void initializeTitle();
	void initializeStartGame();
	void initializeExit();

	Text* getTitle();
	Text* getStartGameText();
	Text* getExitGameText();
};