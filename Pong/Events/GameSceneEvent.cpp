#include "GameSceneEvent.h"

GameSceneEvent::GameSceneEvent(): m_pressedFirstButton(false), m_isMatchFinished(false)
{
}

void GameSceneEvent::handleEvents(Scene* currentScene)
{
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);
	SDL_PollEvent(&m_event);
	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_KEYDOWN: {
		if (!m_pressedFirstButton) {
			obj->getBall().startMoving();
			m_pressedFirstButton = true;
		}

		switch (m_event.key.keysym.sym) {
		case SDLK_DOWN: obj->getPlayerPlatform().moveDown(); break;
		case SDLK_UP: obj->getPlayerPlatform().moveUp(); break;
		}
		break;
	}
	default:
		break;
	}
	update(currentScene);
}

void GameSceneEvent::startMovingBall(Ball &ball)
{
}

void GameSceneEvent::update(Scene* currentScene)
{
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);
	Ball& ball = obj->getBall();
	Platform& playerPlatform = obj->getPlayerPlatform();
	Platform& botPlatform = obj->getBotPlatform();
	

	switch (ball.isOutOfScreen()) {
	case TRUE_LEFT: {
		increaseScoreTextByOne(obj->getBotScoreText());
		resetMatch(currentScene);
		break;
	}
	case TRUE_RIGHT: {
		increaseScoreTextByOne(obj->getPlayerScoreText());
		resetMatch(currentScene);
		break;
	}
	}

	ball.checkCollision(playerPlatform);
	ball.checkCollision(botPlatform);

	ball.changeDirection();
	ball.move();
	ball.checkPositionBot(botPlatform);
}

void GameSceneEvent::increaseScoreTextByOne(Text* text)
{
	 int updateScore = std::stoi(text->getTextContent()) + 1;
	text->changeText(std::to_string(updateScore));

	if (updateScore == 5) {
		m_isMatchFinished = true;
		m_isRunning = false;
	}
}

void GameSceneEvent::resetMatch(Scene* currentScene)
{
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);
	SDL_Delay(2000);

	obj->getPlayerPlatform().reset();
	obj->getBotPlatform().reset();

	obj->getBotPlatform().getRectangle().x = 859 - obj->getPlayerPlatform().getRectangle().x;

	obj->getBall().reset();

	m_pressedFirstButton = false;
}
