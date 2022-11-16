#include "GameScene.h"

GameScene::GameScene()
{
	m_platformOne.x = 20;
	m_platformOne.y = 20;
	m_platformOne.w = 40;
	m_platformOne.h = 40;

	m_platformTwo.x = 520;
	m_platformTwo.y = 20;
	m_platformTwo.w = 40;
	m_platformTwo.h = 40;
}

GameScene::~GameScene()
{
}

void GameScene::playScene(SDL_Renderer* render, SDL_Window* window)
{
	int width, height;
	SDL_GetWindowSize(window, &width, &height);

	SDL_SetRenderDrawColor(render, 121, 121, 121, 255);
	SDL_RenderFillRect(render, &m_platformOne);
	SDL_RenderFillRect(render, &m_platformTwo);


	SDL_RenderDrawLine(render, (width - 1) / 2, 0, (width - 1) / 2, height);

	SDL_RenderPresent(render);
}
