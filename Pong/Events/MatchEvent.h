#pragma once
#include "EventHandler.h"
#include <iostream>
#include "../Scenes/MatchScene.h"

class MatchEvent : public EventHandler
{
	MatchScene* m_scene;
	bool m_pressedFirstButton;
	bool m_isMatchFinished;
public:
	MatchEvent();

	void handleEvents(float dt) override;
	void startMovingBall(Ball& ball);
	void update(float dt);

	void setScene(Scene* scene) override;

	void increaseScoreTextByOne(Text* text);
	void resetMatch();
};

