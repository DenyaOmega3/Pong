#include "MatchEvent.h"

MatchEvent::MatchEvent(): m_pressedFirstButton(false), m_isMatchFinished(false)
{
}

void MatchEvent::handleEvents(float dt)
{
	SDL_PollEvent(&m_event);
	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_KEYDOWN: {
		if (!m_pressedFirstButton) {
			m_scene->getBall().startMoving();
			m_pressedFirstButton = true;
		}

		switch (m_event.key.keysym.sym) {
		case SDLK_DOWN: m_scene->getPlayerPlatform().moveDown(); break;
		case SDLK_UP: m_scene->getPlayerPlatform().moveUp(); break;
		}
		break;
	}
	default:
		break;
	}
	update(dt);
}

void MatchEvent::startMovingBall(Ball &ball)
{
}

void MatchEvent::update(float dt)
{
	Ball& ball = m_scene->getBall();
	Platform& playerPlatform = m_scene->getPlayerPlatform();
	Platform& botPlatform = m_scene->getBotPlatform();
	

	switch (ball.isOutOfScreen()) {
	case TRUE_LEFT: {
		increaseScoreTextByOne(m_scene->getBotScoreText());
		resetMatch();
		break;
	}
	case TRUE_RIGHT: {
		increaseScoreTextByOne(m_scene->getPlayerScoreText());
		resetMatch();
		break;
	}
	}

	ball.checkCollision(playerPlatform);
	ball.checkCollision(botPlatform);

	ball.changeDirection();
	ball.move(dt);
	ball.checkPositionBot(botPlatform);
}

void MatchEvent::setScene(Scene* scene)
{
	m_scene = dynamic_cast<MatchScene*>(scene);
}

void MatchEvent::increaseScoreTextByOne(Text* text)
{
	int updateScore = std::stoi(text->getTextContent()) + 1;
	text->changeText(std::to_string(updateScore));

	if (updateScore == 5) {
		m_isMatchFinished = true;
		m_nextScene = MAIN_MENU;
	}
}

void MatchEvent::resetMatch()
{

	m_scene->getPlayerPlatform().reset();
	m_scene->getBotPlatform().reset();

	m_scene->getBotPlatform().getRectangle().x = 859 - m_scene->getPlayerPlatform().getRectangle().x;

	m_scene->getBall().reset();

	m_pressedFirstButton = false;
}
