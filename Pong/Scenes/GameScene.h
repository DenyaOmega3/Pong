#pragma once
#include "Scene.h"
#include <iostream>

class GameScene : public Scene
{
	SDL_Rect m_platformOne;
	SDL_Rect m_platformTwo;

	SDL_Rect m_ball;

	bool initialized;
	int m_platformOneSpeed;

	//SDL_Rect m_scoreOne;
	//SDL_Rect m_scoreTwo;

public:
	GameScene();
	~GameScene();

	void setPlatforms(SDL_Window* window);
	void playScene(SDL_Renderer* renderer, SDL_Window* window) override;

	SDL_Rect getPlatformOne() const;
	void setPlatformOne(const SDL_Rect &platform);

	SDL_Rect& getBall();
	void setBall(const SDL_Rect& ball);
};

