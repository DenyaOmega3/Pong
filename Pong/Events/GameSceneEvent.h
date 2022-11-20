#pragma once
#include "EventHandler.h"
#include <iostream>
#include "../Scenes/GameScene.h"

class GameSceneEvent : public EventHandler
{
	bool m_pressedFirstButton;
	bool m_isMatchFinished;
public:
	GameSceneEvent();
	void handleEvents(Scene* currentScene) override;
	void startMovingBall(Ball& ball);
	void update(Scene* currentScene);

	void increaseScoreTextByOne(Text* text);
	void resetMatch(Scene* currentScene);
};

