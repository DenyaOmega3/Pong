#pragma once
#include "SDL.h"
#include "../Scenes/Scene.h"

class EventHandler
{
protected:
	SDL_Event m_event;
	bool m_isRunning = true;

public:
	virtual void handleEvents(Scene *currentScene) = 0;
};

