#include "GameScene.h"

GameScene::GameScene() : initialized(false)
{
}

GameScene::~GameScene()
{
}

void GameScene::setPlatforms(SDL_Window* window)
{
	int windowWidth, windowHeight;
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);

	int marginX = 60;
	int rectWidth = 10, rectHeight = 40;

	m_platformOne.x = marginX;
	m_platformOne.y = windowHeight / 2 - rectHeight / 2;
	m_platformOne.w = rectWidth;
	m_platformOne.h = rectHeight;

	m_platformTwo.x = windowWidth - marginX;
	m_platformTwo.y = windowHeight / 2 - rectHeight / 2;
	m_platformTwo.w = rectWidth;
	m_platformTwo.h = rectHeight;
}

void GameScene::playScene(SDL_Renderer* renderer, SDL_Window* window)
{
	if (!initialized) {
		setPlatforms(window);
	}

	int width, height;
	SDL_GetWindowSize(window, &width, &height);

	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderFillRect(renderer, &m_platformOne);
	SDL_RenderFillRect(renderer, &m_platformTwo);


	SDL_RenderDrawLine(renderer, (width - 1) / 2, 0, (width - 1) / 2, height);

	SDL_RenderPresent(renderer);
}
