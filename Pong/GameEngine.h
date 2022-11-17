#pragma once
#include "Scenes/GameScene.h"
#include "Scenes/MainMenu.h"
#include "Events/GameSceneEvent.h"

class GameEngine
{
	Scene* m_currentScene;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;
	EventHandler* m_eventHandler;

public:
	GameEngine();
	~GameEngine();

	void renderScene();
	void update();
	void handleEvents();

	bool isGameRunning() const;
};

