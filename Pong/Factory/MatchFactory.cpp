#include "MatchFactory.h"

Scene* MatchFactory::createScene()
{
	return new MatchScene();
}

EventHandler* MatchFactory::createEventHandler()
{
	return new MatchEvent();
}
