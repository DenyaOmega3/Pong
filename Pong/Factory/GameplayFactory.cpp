#include "GameplayFactory.h"

Scene* GameplayFactory::createScene()
{
	return new GameScene();
}

EventHandler* GameplayFactory::createEventHandler()
{
	return new GameSceneEvent();
}
