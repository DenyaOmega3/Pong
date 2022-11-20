#include "GameScene.h"

GameScene::GameScene() : m_playerPlatform(),
m_botPlatform(m_playerPlatform), m_ball()
{
	initializePlayerScoreText();
	initializeBotScoreText();

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

	m_playerScore->loadTexture(renderer);
	m_botScore->loadTexture(renderer);

	m_playerScore->render(renderer);
	m_botScore->render(renderer);

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

Text* GameScene::getPlayerScoreText()
{
	return m_playerScore;
}

Text* GameScene::getBotScoreText()
{
	return m_botScore;
}

void GameScene::setBall(const SDL_Rect& ball)
{
	m_ball = ball;
}

void GameScene::initializePlayerScoreText()
{
	TextDirector* director = new TextDirector();

	PixelTextBuilder* pixelTextBuilderWithRectangle = new PixelTextBuilder();
	pixelTextBuilderWithRectangle
		->buildSize(24)
		->buildColor({ 255,255,255 })
		->buildTextContent("0")
		->buildPosition(858 / 4.0, 50);

	director->setBuilder(pixelTextBuilderWithRectangle);
	director->buildText();

	m_playerScore = pixelTextBuilderWithRectangle->getBuiltText();
	delete pixelTextBuilderWithRectangle;
	delete director;
}

void GameScene::initializeBotScoreText()
{
	TextDirector* director = new TextDirector();

	PixelTextBuilder* pixelTextBuilderWithRectangle = new PixelTextBuilder();
	pixelTextBuilderWithRectangle
		->buildSize(24)
		->buildColor({ 255,255,255 })
		->buildTextContent("0")
		->buildPosition(858 * 3/ 4.0, 50);

	director->setBuilder(pixelTextBuilderWithRectangle);
	director->buildText();

	m_botScore = pixelTextBuilderWithRectangle->getBuiltText();
	delete pixelTextBuilderWithRectangle;
	delete director;
}
