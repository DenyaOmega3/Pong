#pragma once
#include "SDL_ttf.h"
#include "Events/GameSceneEvent.h"

class GameEngine
{
	Scene* m_currentScene;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;
	EventHandler* m_eventHandler;

	static GameEngine* m_uniqueEngine;

	GameEngine();
public:
	~GameEngine();
	GameEngine(const GameEngine& obj) = delete;
	void operator=(const GameEngine& obj) = delete;

	void renderScene();
	void update();
	void handleEvents();

	bool isGameRunning() const;

	static GameEngine* getInstance();

	SDL_Window* getWindow();
};

