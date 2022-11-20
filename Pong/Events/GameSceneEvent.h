#pragma once
#include "EventHandler.h"
#include <iostream>
#include "../Scenes/GameScene.h"

class GameSceneEvent : public EventHandler
{
	GameScene* m_scene;
	bool m_pressedFirstButton;
	bool m_isMatchFinished;
public:
	GameSceneEvent();

	void handleEvents(float dt) override;
	void startMovingBall(Ball& ball);
	void update(float dt);

	void setScene(Scene* scene) override;

	void increaseScoreTextByOne(Text* text);
	void resetMatch();
};

