#include "MainMenuEvent.h"

void MainMenuEvent::handleEvents(float dt)
{
	m_nextScene = NONE;
	SDL_PollEvent(&m_event);
	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN: {
		int x, y;
		SDL_PumpEvents();
		SDL_GetMouseState(&x, &y);
		if (checkIfPressed(x, y, m_scene->getStartGameText()->getDstRectangle())) {
			m_nextScene = MATCH;
		}
		if (checkIfPressed(x, y, m_scene->getExitGameText()->getDstRectangle()))
			m_isRunning = false;

		break;
	}
	default:
		break;
	}
}

void MainMenuEvent::setScene(Scene* scene)
{
	m_scene = dynamic_cast<MainMenu*>(scene);
}

bool MainMenuEvent::checkIfPressed(int xMouse, int yMouse, const SDL_Rect& rectangle)
{
	return (xMouse >= rectangle.x && xMouse <= rectangle.x + rectangle.w
		&& yMouse >= rectangle.y && yMouse <= rectangle.y + rectangle.h);
}
