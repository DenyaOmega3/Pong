#include "GameEngine.h"

GameEngine* GameEngine::m_uniqueEngine = nullptr;

GameEngine::GameEngine() : m_isRunning(true)
{
	assert(!SDL_Init(SDL_INIT_EVERYTHING), "SDL hasn't initialized");
	assert(!TTF_Init(), "TTF hasn't initialized");

	MainMenuFactory* factory = new MainMenuFactory();
	m_currentScene = factory->createScene();
	m_eventHandler = factory->createEventHandler();

	m_window = SDL_CreateWindow(
		"Pong", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

	delete factory;
}

GameEngine::~GameEngine() {
	delete m_currentScene;
	delete m_eventHandler;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	SDL_Quit();
	TTF_Quit();
}

void GameEngine::renderScene() {
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	m_currentScene->playScene(m_renderer, m_window);
}

void GameEngine::handleEvents()
{
	m_eventHandler->handleEvents(m_currentScene);
	m_isRunning = m_eventHandler->isRunning(); 
}

bool GameEngine::isGameRunning() const
{
	return m_isRunning;
}

void GameEngine::stopRunning()
{
}

GameEngine* GameEngine::getInstance()
{
	if (!m_uniqueEngine)
		m_uniqueEngine = new GameEngine();
	return m_uniqueEngine;
}

SDL_Window* GameEngine::getWindow()
{
	return m_window;
}