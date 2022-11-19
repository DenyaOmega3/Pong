#pragma once
#include "Scene.h"
#include "../Objects/Platform/Platform.h"
#include "../Objects/Ball/Ball.h"
#include "../Objects/Text/Text.h"
#include <iostream>
#include "../Objects/Text/TextDirector.h"
#include "../Objects/Text/Builders/PixelTextBuilder.h"


class GameScene : public Scene
{
	Platform m_playerPlatform;
	Platform m_botPlatform;

	Ball m_ball;

	bool initialized;

	Text *m_playerScore;
	Text *m_botScore;

public:
	GameScene();
	~GameScene();

	void setPlatforms(SDL_Window* window);
	void playScene(SDL_Renderer* renderer, SDL_Window* window) override;

	Platform& getPlayerPlatform();
	Platform& getBotPlatform();

	Ball& getBall();
	void setBall(const SDL_Rect& ball);

	void initializePlayerScoreText();
	void initializeBotScoreText();
};