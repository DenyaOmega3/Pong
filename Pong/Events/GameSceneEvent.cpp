#include "GameSceneEvent.h"

void GameSceneEvent::handleEvents(Scene* currentScene)
{
	SDL_PollEvent(&m_event);
	GameScene* obj = dynamic_cast<GameScene*>(currentScene);

	moveBall(obj->getBall());

	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_KEYDOWN: {
		SDL_Rect pl = obj->getPlatformOne();

		switch (m_event.key.keysym.sym) {
		case SDLK_DOWN: movePlatformDown(pl); break;
		case SDLK_UP: movePlatformUp(pl); break;
		}
		obj->setPlatformOne(pl);
		break;
	}
	default:
		break;
	}
}

void GameSceneEvent::movePlatformDown(SDL_Rect &platform)
{
	platform.y += 5;
}

void GameSceneEvent::movePlatformUp(SDL_Rect& platform)
{
	platform.y -= 5;
}

void GameSceneEvent::moveBall(SDL_Rect& ball)
{


	ball.x += ball.w;
	ball.y += ball.h;
}
