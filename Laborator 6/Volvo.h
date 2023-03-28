#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
    Volvo();
    double getFuelCapacity();
    double getFuelConsumption();
    double getAvgSpeed(Weather weather);
    char* getName();
};