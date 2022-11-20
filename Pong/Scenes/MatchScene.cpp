#include "MatchScene.h"

MatchScene::MatchScene() : m_playerPlatform(),
m_botPlatform(m_playerPlatform), m_ball()
{
	initializePlayerScoreText();
	initializeBotScoreText();

	m_botPlatform.getRectangle().x = windowWidth - m_botPlatform.getRectangle().x;
}

MatchScene::~MatchScene()
{
}

void MatchScene::setPlatforms(SDL_Window* window)
{
}

void MatchScene::renderScene(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderFillRect(renderer, &m_playerPlatform.getRectangle());
	SDL_RenderFillRect(renderer, &m_botPlatform.getRectangle());
	SDL_RenderFillRect(renderer, &m_ball.getRectangle());

	SDL_RenderDrawLine(renderer, (windowWidth - 1) / 2, 0, (windowWidth - 1) / 2, windowHeight);

	m_playerScore->loadTexture(renderer);
	m_botScore->loadTexture(renderer);

	m_playerScore->render(renderer);
	m_botScore->render(renderer);

	SDL_RenderPresent(renderer);
}

Platform& MatchScene::getPlayerPlatform()
{
	return m_playerPlatform;
}

Platform& MatchScene::getBotPlatform()
{
	return m_botPlatform;
}

Ball& MatchScene::getBall()
{
	return m_ball;
}

Text* MatchScene::getPlayerScoreText()
{
	return m_playerScore;
}

Text* MatchScene::getBotScoreText()
{
	return m_botScore;
}

void MatchScene::setBall(const SDL_Rect& ball)
{
	m_ball = ball;
}

void MatchScene::initializePlayerScoreText()
{
	TextDirector* director = new TextDirector();

	PixelTextBuilder* pixelTextBuilderWithRectangle = new PixelTextBuilder();
	pixelTextBuilderWithRectangle
		->buildSize(24)
		->buildColor({ 255,255,255 })
		->buildTextContent("0")
		->buildPosition((windowWidth-1) / 4.0, 50);

	director->setBuilder(pixelTextBuilderWithRectangle);
	director->buildText();

	m_playerScore = pixelTextBuilderWithRectangle->getBuiltText();
	delete pixelTextBuilderWithRectangle;
	delete director;
}

void MatchScene::initializeBotScoreText()
{
	TextDirector* director = new TextDirector();

	PixelTextBuilder* pixelTextBuilderWithRectangle = new PixelTextBuilder();
	pixelTextBuilderWithRectangle
		->buildSize(24)
		->buildColor({ 255,255,255 })
		->buildTextContent("0")
		->buildPosition((windowWidth-1) * 3/ 4.0, 50);

	director->setBuilder(pixelTextBuilderWithRectangle);
	director->buildText();

	m_botScore = pixelTextBuilderWithRectangle->getBuiltText();
	delete pixelTextBuilderWithRectangle;
	delete director;
}
