#include "MainMenu.h"

MainMenu::MainMenu() : 
	m_textStartGameButton("arial.ttf", 24, { 255,255,255 }, "Start Game",0,0), 
	m_startGameButton(m_textStartGameButton),
	m_textExitButton("arial.ttf", 24, { 255,255,255 }, "Exit", 0, 60),
	m_exitButton(m_textExitButton)
{
}

void MainMenu::playScene(SDL_Renderer* renderer, SDL_Window* window)
{
	m_startGameButton.render(renderer);
	m_exitButton.render(renderer);
	SDL_RenderPresent(renderer);
}
