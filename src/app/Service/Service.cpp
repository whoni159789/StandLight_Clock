#include "Service.h"

Service::Service(View *viewer)
{
    lightState = LIGHT_OFF;
    backlightState = BACKLIGHT_ON;
    view = viewer;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_2;
                view->setState(lightState);
            }
        break;

        case LIGHT_2:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_3;
                view->setState(lightState);
            }
        break;

        case LIGHT_3:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_4;
                view->setState(lightState);
            }
        break;

        case LIGHT_4:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_5;
                view->setState(lightState);
            }
        break;

        case LIGHT_5:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
    }

    switch(backlightState)
    {
        case BACKLIGHT_OFF:
            if(strState == "powerButton")
            {
                backlightState = BACKLIGHT_ON;
                view->backlightsetState(backlightState);
            }
        break;

        case BACKLIGHT_ON:
            if(strState == "powerButton")
            {
                backlightState = BACKLIGHT_OFF;
                view->backlightsetState(backlightState);
            }

        break;
    }
}