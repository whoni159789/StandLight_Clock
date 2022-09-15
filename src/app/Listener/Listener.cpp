#include "Listener.h"

Listener::Listener(Button *button, Button *bklight, ClockCheck *clock, Controller *control)
{
    powerButton = button;
    backlightButton = bklight;
    clockcheck = clock;
    controller = control;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if(powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }
    if(backlightButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }
    if(clockcheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }
}