#include "MainMenuFactory.h"

Scene* MainMenuFactory::createScene()
{
	return new MainMenu();
}

EventHandler* MainMenuFactory::createEventHandler()
{
	return new MainMenuEvent();
}
