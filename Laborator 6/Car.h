#pragma once

#include "Weather.h"

class Car
{
protected:
    double fuelCapacity, fuelConsumption, avgSpeedRain, avgSpeedSun, avgSpeedSnow;
    char* name;
public:
    virtual double getFuelCapacity() = 0;
    virtual double getFuelConsumption() = 0;
    virtual double getAvgSpeed(Weather weather) = 0;
    virtual char* getName() = 0;
};