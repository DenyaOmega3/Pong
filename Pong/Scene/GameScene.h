#pragma once
#include "Scene.h"

class GameScene : public Scene
{
	SDL_Rect m_platformOne;
	SDL_Rect m_platformTwo;

	SDL_Rect m_ball;

	bool initialized;

	//SDL_Rect m_scoreOne;
	//SDL_Rect m_scoreTwo;

public:
	GameScene();
	~GameScene();

	void setPlatforms(SDL_Window* window);
	void playScene(SDL_Renderer* renderer, SDL_Window* window) override;
};

