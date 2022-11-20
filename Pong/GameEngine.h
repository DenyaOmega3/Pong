#pragma once
#include "SDL_ttf.h"
#include "Factory/GameplayFactory.h"
#include "Factory/MainMenuFactory.h"

#define WINDOW_WIDTH 859
#define WINDOW_HEIGHT 524

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
	void handleEvents();

	bool isGameRunning() const;

	void stopRunning();

	static GameEngine* getInstance();

	SDL_Window* getWindow();
};

