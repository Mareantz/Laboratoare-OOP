#pragma once
#include "Car.h"
class BMW : public Car
{
public:
    BMW();
    double getFuelCapacity();
    double getFuelConsumption();
    double getAvgSpeed(Weather weather);
    char* getName();
};