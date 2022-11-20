#pragma once
#include "SDL.h"
#include "../Scenes/Scene.h"

enum NextScene { NONE = 0, MAIN_MENU, MATCH };

class EventHandler
{
protected:
	NextScene m_nextScene;
	SDL_Event m_event;
	bool m_isRunning = true;

public:
	EventHandler();
	virtual void handleEvents(float dt) = 0;
	bool isRunning();
	NextScene getNextScene();
	virtual void setScene(Scene* scene) = 0;
};

