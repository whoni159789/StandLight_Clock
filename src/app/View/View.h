#ifndef __VIEW_H__
#define __VIEW_H__

#pragma once

#include <string>
#include "Led.h"
#include "lightState.h"
#include "backlightState.h"
#include "LCD.h"

class View
{
private:
    int lightState;
    int backlightState;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;
    LCD *light_lcd;

public:
    View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *light_LCD);
    virtual ~View();
    void setState(int state);
    void lightView();
    void lightOff();
    void lightOn1();
    void lightOn2();
    void lightOn3();
    void lightOn4();
    void lightOn5();

    void lcdView();
    void lightOff_lcd();
    void lightOn1_lcd();
    void lightOn2_lcd();
    void lightOn3_lcd();
    void lightOn4_lcd();
    void lightOn5_lcd();

    void backlightsetState(int state);
    void backlightView();
    void backlightOff();
    void backlightOn();
};

#endif /* __VIEW_H__ */