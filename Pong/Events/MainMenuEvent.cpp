#include "MainMenuEvent.h"

void MainMenuEvent::handleEvents(Scene* currentScene)
{
	SDL_PollEvent(&m_event);
	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	default:
		break;
	}
}
