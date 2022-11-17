#include "GameScene.h"

GameScene::GameScene() : initialized(false), m_platformOneSpeed(5)
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

	m_platformOne = SDL_Rect{ marginX, windowHeight / 2 - rectHeight / 2, rectWidth, rectHeight };
	m_platformTwo = SDL_Rect{ windowWidth - marginX, windowHeight / 2 - rectHeight / 2, rectWidth, rectHeight };

	int halfSize = 4;
	m_ball = SDL_Rect{ windowWidth / 2 - halfSize, windowHeight / 2 - halfSize, 2* halfSize,2* halfSize };
}

void GameScene::playScene(SDL_Renderer* renderer, SDL_Window* window)
{
	if (!initialized) {
		setPlatforms(window);
		initialized = true;
	}

	int width, height;
	SDL_GetWindowSize(window, &width, &height);

	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderFillRect(renderer, &m_platformOne);
	SDL_RenderFillRect(renderer, &m_platformTwo);
	SDL_RenderFillRect(renderer, &m_ball);


	SDL_RenderDrawLine(renderer, (width - 1) / 2, 0, (width - 1) / 2, height);

	SDL_RenderPresent(renderer);
}

SDL_Rect GameScene::getPlatformOne() const
{
	return m_platformOne;
}

void GameScene::setPlatformOne(const SDL_Rect& platform)
{
	m_platformOne = platform;
}

SDL_Rect& GameScene::getBall()
{
	std::cout << m_ball.x << std::endl;
	return m_ball;
}

void GameScene::setBall(const SDL_Rect& ball)
{
	m_ball = ball;
}
