#include "MainMenuEvent.h"

void MainMenuEvent::handleEvents(Scene* currentScene)
{
	MainMenu* obj = dynamic_cast<MainMenu*>(currentScene);
	SDL_PollEvent(&m_event);
	switch (m_event.type) {
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN: {
		int x, y;
		SDL_PumpEvents();
		SDL_GetMouseState(&x, &y);
		if (checkIfPressed(x, y, obj->getStartGameText()->getDstRectangle())) {
			std::cout << "start game" << std::endl;
		}
		if (checkIfPressed(x, y, obj->getExitGameText()->getDstRectangle()))
			m_isRunning = false;

		break;
	}
	default:
		break;
	}
}

bool MainMenuEvent::checkIfPressed(int xMouse, int yMouse, const SDL_Rect& rectangle)
{
	return (xMouse >= rectangle.x && xMouse <= rectangle.x + rectangle.w
		&& yMouse >= rectangle.y && yMouse <= rectangle.y + rectangle.h);
}
