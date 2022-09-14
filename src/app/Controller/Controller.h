#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#pragma once

#include <string>
#include "Service.h"
#include "ClockService.h"

class Controller
{
private:
    Service *service;
    ClockService *clockservice;

public:
    Controller(Service *serv, ClockService *clkserv);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
};

#endif /* __CONTROLLER_H__ */