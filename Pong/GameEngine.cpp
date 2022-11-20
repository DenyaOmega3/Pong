#include "GameEngine.h"

GameEngine* GameEngine::m_uniqueEngine = nullptr;

GameEngine::GameEngine() : m_isRunning(true)
{
	initializeSDL();
	loadSceneWithEvents(new MainMenuFactory());
	initializeWindow();
	initializeRenderer();
}

GameEngine::~GameEngine() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	removeSceneWithEvenets();
	closeSDL();
}

void GameEngine::initializeSDL()
{
	assert(!SDL_Init(SDL_INIT_EVERYTHING), "SDL hasn't initialized");
	assert(!TTF_Init(), "TTF hasn't initialized");
}

void GameEngine::closeSDL()
{
	SDL_Quit();
	TTF_Quit();
}

void GameEngine::loadSceneWithEvents(EngineFactory* factory)
{
	m_currentScene = factory->createScene();
	m_eventHandler = factory->createEventHandler();
	m_eventHandler->setScene(m_currentScene);
	delete factory;
}

void GameEngine::removeSceneWithEvenets()
{
	delete m_currentScene;
	delete m_eventHandler;
}

void GameEngine::changeSceneWithEvents(EngineFactory *factory)
{
	removeSceneWithEvenets();
	loadSceneWithEvents(factory);
}

void GameEngine::initializeWindow()
{
	m_window = SDL_CreateWindow(
		windowName.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight,
		SDL_WINDOW_SHOWN);
}

void GameEngine::initializeRenderer()
{
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
}

void GameEngine::renderScene() {
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	m_currentScene->renderScene(m_renderer);
}

void GameEngine::handleEvents()
{
	m_eventHandler->handleEvents(m_deltaTime);
	m_isRunning = m_eventHandler->isRunning();
	changeSceneIfNeeded();
}

void GameEngine::changeSceneIfNeeded()
{
	NextScene changeScene = m_eventHandler->getNextScene();
	
	switch (changeScene)
	{
	case MAIN_MENU: {
		changeSceneWithEvents(new MainMenuFactory());
		break;
	}
	case MATCH: {
		changeSceneWithEvents(new MatchFactory());
		break;
	}
	default:
		break;
	}
}

bool GameEngine::isGameRunning() const
{
	return m_isRunning;
}

void GameEngine::loadDeltaTime()
{
	m_prevTime = m_currTime;
	m_currTime = SDL_GetTicks();
	m_deltaTime = (m_currTime - m_prevTime) / 1000.0f;
}

float GameEngine::getDeltaTime() const
{
	return m_deltaTime;
}

GameEngine* GameEngine::getInstance()
{
	if (!m_uniqueEngine)
		m_uniqueEngine = new GameEngine();
	return m_uniqueEngine;
}
