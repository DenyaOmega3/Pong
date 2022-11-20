#include "MainMenu.h"

MainMenu::MainMenu() {
	initializeTitle();
	initializeStartGame();
	initializeExit();
}

MainMenu::~MainMenu()
{
	delete m_title;
	delete m_textStartGame;
	delete m_textExitGame;
}

void MainMenu::renderScene(SDL_Renderer* renderer)
{
	m_title->loadTexture(renderer);
	m_title->render(renderer);

	m_textStartGame->loadTexture(renderer);
	m_textStartGame->render(renderer);

	m_textExitGame->loadTexture(renderer);
	m_textExitGame->render(renderer);

	SDL_RenderPresent(renderer);
}

void MainMenu::initializeTitle()
{
	TextDirector* director = new TextDirector();

	PixelTextBuilder* pixelTextBuilderWithRectangle = new PixelTextBuilder();
	pixelTextBuilderWithRectangle
		->buildSize(40)
		->buildColor({ 255,255,255 })
		->buildTextContent("Pong")
		->buildPosition(858 / 2, 50);

	director->setBuilder(pixelTextBuilderWithRectangle);
	director->buildText();

	m_title = pixelTextBuilderWithRectangle->getBuiltText();
	delete pixelTextBuilderWithRectangle;
	delete director;
}

void MainMenu::initializeStartGame()
{
	TextDirector* director = new TextDirector();

	ArialTextWithRectangleBuilder* arialTextWithRectangle = new ArialTextWithRectangleBuilder();
	arialTextWithRectangle
		->buildSize(24)
		->buildColor({ 255,255,255 })
		->buildTextContent("Start Game")
		->buildDstRectangleColor()
		->buildPosition((windowWidth - 1) / 2, 200 * windowWidth/859.0);

	director->setBuilder(arialTextWithRectangle);
	director->buildText();

	m_textStartGame = arialTextWithRectangle->getBuiltText();
	delete arialTextWithRectangle;
	delete director;
}

void MainMenu::initializeExit()
{
	TextDirector* director = new TextDirector();

	ArialTextWithRectangleBuilder* arialTextWithRectangle = new ArialTextWithRectangleBuilder();
	arialTextWithRectangle
		->buildSize(24)
		->buildColor({ 255,255,255 })
		->buildTextContent("Exit Game")
		->buildDstRectangleColor()
		->buildPosition(858 / 2, 250);

	director->setBuilder(arialTextWithRectangle);
	director->buildText();

	m_textExitGame = arialTextWithRectangle->getBuiltText();
	delete arialTextWithRectangle;
	delete director;
}

Text* MainMenu::getTitle()
{
	return m_title;
}

Text* MainMenu::getStartGameText()
{
	return m_textStartGame;
}

Text* MainMenu::getExitGameText()
{
	return m_textExitGame;
}
