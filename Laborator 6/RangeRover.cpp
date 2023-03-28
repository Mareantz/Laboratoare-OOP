#define _CRT_SECURE_NO_WARNINGS
#include "RangeRover.h"
#include "Weather.h"
#include <cstring>

RangeRover::RangeRover()
{
    fuelCapacity = 101;
    fuelConsumption = 14.9;
    avgSpeedRain = 90;
    avgSpeedSnow = 70;
    avgSpeedSun = 120;
    name = new char[11];
    strcpy(this->name, "RangeRover");
};

double RangeRover::getAvgSpeed(Weather weather)
{
    switch (weather)
    {
    case(Sun):
        return this->avgSpeedSun;
    case(Snow):
        return this->avgSpeedSnow;
    case(Rain):
        return this->avgSpeedRain;
    }
}

double RangeRover::getFuelCapacity()
{
    return this->fuelCapacity;
}

double RangeRover::getFuelConsumption()
{
    return this->fuelConsumption;
}

char* RangeRover::getName()
{
    return this->name;
}