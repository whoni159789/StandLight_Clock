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

void View::lcdView()
{
    switch(lightState)
    {
        case LIGHT_OFF:
            lightOff_lcd();
            break;

        case LIGHT_1:
            lightOn1_lcd();
            break;

        case LIGHT_2:
            lightOn2_lcd();
            break;

        case LIGHT_3:
            lightOn3_lcd();
            break;

        case LIGHT_4:
            lightOn4_lcd();
            break;

        case LIGHT_5:
            lightOn5_lcd();
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
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn1()
{
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn2()
{
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn3()
{
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn4()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn5()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff_lcd()
{
    light_lcd->WriteStringXY(0, 0, "LED Power OFF   ");   
}

void View::lightOn1_lcd()
{
    light_lcd->WriteStringXY(0, 0, "LED First Stage ");
}

void View::lightOn2_lcd()
{
    light_lcd->WriteStringXY(0, 0, "LED Second Stage");
}

void View::lightOn3_lcd()
{
    light_lcd->WriteStringXY(0, 0, "LED Third Stage ");
}
void View::lightOn4_lcd()
{
    light_lcd->WriteStringXY(0, 0, "LED Fourth Stage");
}

void View::lightOn5_lcd()
{
    light_lcd->WriteStringXY(0, 0, "LED Fifth Stage ");
}

void View::backlightOff()
{
    light_lcd->backLightOff();
}

void View::backlightOn()
{
    light_lcd->backLightOn();
}