#include "GameSceneEvent.h"

void GameSceneEvent::handleEvents(Scene* currentScene)
{
	SDL_PollEvent(&m_event);
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);
	obj->getBall().checkCollision(obj->getPlayerPlatform(), obj->getBotPlatform());
	obj->getBall().checkPositionBot(obj->getBotPlatform());
	obj->getBall().move();
	

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
}