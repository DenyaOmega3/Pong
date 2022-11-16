#include "GameEngine.h"

GameEngine::GameEngine() : m_isRunning(true)
{
	m_currentScene = new MainMenu();
	m_window = SDL_CreateWindow(
		"Pong", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		859, 525,
		SDL_WINDOW_RESIZABLE);

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
}

GameEngine::~GameEngine() {
	delete m_currentScene;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void GameEngine::renderScene() {
	m_currentScene->playScene(m_renderer, m_window);
}

void GameEngine::update()
{
}

void GameEngine::handleEvents()
{
	SDL_Event events;
	SDL_PollEvent(&events);


	switch (events.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	default:
		break;
	}
}

bool GameEngine::isGameRunning() const
{
	return m_isRunning;
}