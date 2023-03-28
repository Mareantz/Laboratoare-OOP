#pragma once
#include "Car.h"
class Seat : public Car
{
public:
    Seat();
    double getFuelCapacity();
    double getFuelConsumption();
    double getAvgSpeed(Weather weather);
    char* getName();
};