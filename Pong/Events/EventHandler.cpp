#include "EventHandler.h"

EventHandler::EventHandler()
{
    m_nextScene = NONE;
}

bool EventHandler::isRunning()
{
    return m_isRunning;
}

NextScene EventHandler::getNextScene()
{
    return m_nextScene;
}
