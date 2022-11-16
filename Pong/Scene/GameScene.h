#pragma once
#include "Scene.h"

class GameScene : public Scene
{
	SDL_Rect m_platformOne;
	SDL_Rect m_platformTwo;

	SDL_Rect m_ball;

	//SDL_Rect m_scoreOne;
	//SDL_Rect m_scoreTwo;

public:
	GameScene();
	~GameScene();

	void playScene(SDL_Renderer* render, SDL_Window* window) override;
};

