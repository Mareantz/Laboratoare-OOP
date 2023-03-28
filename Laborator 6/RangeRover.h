#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
    RangeRover();
    double getFuelCapacity();
    double getFuelConsumption();
    double getAvgSpeed(Weather weather);
    char* getName();
};