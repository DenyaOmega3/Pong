#include "MainMenu.h"

MainMenu::MainMenu()
{
}

void MainMenu::playScene(SDL_Renderer* render, SDL_Window* window)
{
	m_startGameButton.loadTexture(render);
	m_startGameButton.render(render);
	SDL_RenderPresent(render);
}
