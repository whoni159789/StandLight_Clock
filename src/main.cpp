 #include <iostream>
 #include <wiringPi.h>
//src
#include "Button.h"
#include "Led.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "LCD.h"

//app
#include "Listener.h"
#include "Controller.h"
#include "Service.h"
#include "ClockService.h"
#include "View.h"
#include "ClockView.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Button button1(27);
    Button button2(28);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    LCD lcd(new I2C("/dev/i2c-1", 0x25));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockview(&lcd);
    Service service(&view);
    ClockService clockservice(&clockview);
    Controller control(&service, &clockservice);
    ClockCheck clockcheck;
    Listener listener(&button1, &button2, &clockcheck, &control);
    
     while (1)
     {
        listener.checkEvent();
        view.backlightView();
        view.lightView();
        view.lcdView();
        delay(50);
     }

    return 0;
}