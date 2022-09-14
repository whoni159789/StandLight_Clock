#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clkserv)
{
    service = serv;
    clockservice = clkserv;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if(strBtn == "modeButton") 
    {
        service->updateState("modeButton");
    }
    
    if(strBtn == "backlightButton")
    {
        service->updateState("backlightButton");
    }

    if(strBtn == "clockUpdate")
    {
        clockservice->updateEvent();
    }
}