#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
    Fiat();
    double getFuelCapacity();
    double getFuelConsumption();
    double getAvgSpeed(Weather weather);
    char* getName();
};