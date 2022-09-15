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
    
    if(strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if(strBtn == "clockUpdate")
    {
        clockservice->updateEvent();
    }
}