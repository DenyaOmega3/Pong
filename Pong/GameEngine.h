#pragma once
#include "Scene/GameScene.h"
#include "Scene/MainMenu.h"

class GameEngine
{
	Scene* m_currentScene;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;

public:
	GameEngine();
	~GameEngine();

	void renderScene();
	void update();
	void handleEvents();

	bool isGameRunning() const;
};

