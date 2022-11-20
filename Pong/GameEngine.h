#pragma once
#include "SDL_ttf.h"
#include "Factory/GameplayFactory.h"
#include "Factory/MainMenuFactory.h"
#include "preferences.h"

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

	void initializeSDL();
	void closeSDL();
	void loadSceneWithEvents(EngineFactory* factory);
	void removeSceneWithEvenets();
	void changeSceneWithEvents(EngineFactory* factory);

	void renderScene();
	void handleEvents();
	void changeSceneIfNeeded();

	bool isGameRunning() const;

	void stopRunning();

	static GameEngine* getInstance();

	SDL_Window* getWindow();
};

