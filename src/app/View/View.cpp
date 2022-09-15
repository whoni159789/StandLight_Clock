#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *light_LCD)
{
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    light_lcd = light_LCD;
    lightState = LIGHT_OFF;
    backlightState = BACKLIGHT_ON;
}

View::~View()
{

}

void View::setState(int state)
{
    lightState = state;
}

void View::backlightsetState(int state)
{
    backlightState = state;
}

void View::lightView()
{
    switch(lightState)
    {
        case LIGHT_OFF:
            lightOff();
            break;

        case LIGHT_1:
            lightOn1();
            break;

        case LIGHT_2:
            lightOn2();
            break;

        case LIGHT_3:
            lightOn3();
            break;

        case LIGHT_4:
            lightOn4();
            break;

        case LIGHT_5:
            lightOn5();
            break;
     }
}

void View::backlightView()
{
    switch(backlightState)
    {
        case BACKLIGHT_OFF:
            backlightOff();
        break;

        case BACKLIGHT_ON:
            backlightOn();
        break;
    }
}

void View::lightOff()
{
    char buff[30];
    sprintf(buff, "Light Bright : 0");
    light_lcd->WriteStringXY(0, 0, buff);

    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn1()
{
    char buff[30];
    sprintf(buff, "Light Bright : 1");
    light_lcd->WriteStringXY(0, 0, buff);

    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn2()
{
    char buff[30];
    sprintf(buff, "Light Bright : 2");
    light_lcd->WriteStringXY(0, 0, buff);

    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn3()
{
    char buff[30];
    sprintf(buff, "Light Bright : 3");
    light_lcd->WriteStringXY(0, 0, buff);

    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn4()
{
    char buff[30];
    sprintf(buff, "Light Bright : 4");
    light_lcd->WriteStringXY(0, 0, buff);

    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn5()
{
    char buff[30];
    sprintf(buff, "Light Bright : 5");
    light_lcd->WriteStringXY(0, 0, buff);

    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}


void View::backlightOff()
{
    light_lcd->backLightOff();
}

void View::backlightOn()
{
    light_lcd->backLightOn();
}