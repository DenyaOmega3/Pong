#include "GameSceneEvent.h"

void GameSceneEvent::handleEvents(Scene* currentScene)
{
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);
	SDL_PollEvent(&m_event);
	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_KEYDOWN: {
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

void GameSceneEvent::update(Scene* currentScene)
{
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);
	Ball& ball = obj->getBall();
	Platform& playerPlatform = obj->getPlayerPlatform();
	Platform& botPlatform = obj->getBotPlatform();

	ball.checkCollision(playerPlatform);
	ball.checkCollision(botPlatform);
	ball.changeDirection();
	ball.move();
	ball.checkPositionBot(botPlatform);
}
