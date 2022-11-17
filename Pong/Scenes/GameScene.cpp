#include "GameScene.h"

GameScene::GameScene() : m_playerPlatform(), initialized(false),
m_botPlatform(m_playerPlatform), m_ball()
{
	m_botPlatform.getRectangle().x = 859 - m_botPlatform.getRectangle().x;
}

GameScene::~GameScene()
{
}

void GameScene::setPlatforms(SDL_Window* window)
{
}

void GameScene::playScene(SDL_Renderer* renderer, SDL_Window* window)
{
	int width, height;
	SDL_GetWindowSize(window, &width, &height);

	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderFillRect(renderer, &m_playerPlatform.getRectangle());
	SDL_RenderFillRect(renderer, &m_botPlatform.getRectangle());
	SDL_RenderFillRect(renderer, &m_ball.getRectangle());

	SDL_RenderDrawLine(renderer, (width - 1) / 2, 0, (width - 1) / 2, height);

	SDL_RenderPresent(renderer);
}

Platform& GameScene::getPlayerPlatform()
{
	return m_playerPlatform;
}

Platform& GameScene::getBotPlatform()
{
	return m_botPlatform;
}

Ball& GameScene::getBall()
{
	return m_ball;
}

void GameScene::setBall(const SDL_Rect& ball)
{
	m_ball = ball;
}
