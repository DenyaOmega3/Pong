#pragma once
#include "Scene.h"
#include "../Objects/Platform/Platform.h"
#include "../Objects/Ball/Ball.h"
#include <iostream>
#include <chrono>

class GameScene : public Scene
{
	Platform m_playerPlatform;
	Platform m_botPlatform;

	Ball m_ball;

	bool initialized;

	//SDL_Rect m_scoreOne;
	//SDL_Rect m_scoreTwo;

public:
	GameScene();
	~GameScene();

	void setPlatforms(SDL_Window* window);
	void playScene(SDL_Renderer* renderer, SDL_Window* window) override;

	Platform& getPlayerPlatform();
	Platform& getBotPlatform();

	Ball& getBall();
	void setBall(const SDL_Rect& ball);
};