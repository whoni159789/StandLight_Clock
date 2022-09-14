#ifndef __LISTENER_H__
#define __LISTENER_H__

#pragma once

#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"

class Listener
{
private :
    Button *powerButton;
    Button *backlightButton;
    Controller *controller;
    ClockCheck *clockcheck;

public:
    Listener(Button *button, Button *bklight, ClockCheck *clock, Controller *control);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
