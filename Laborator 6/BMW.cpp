#define _CRT_SECURE_NO_WARNINGS
#include "BMW.h"
#include "Weather.h"
#include <cstring>

BMW::BMW()
{
    fuelCapacity = 48;
    fuelConsumption = 56;
    avgSpeedRain = 72;
    avgSpeedSnow = 58;
    avgSpeedSun = 103;
    name = new char[4];
    strcpy(this->name, "BMW");
};

double BMW::getAvgSpeed(Weather weather)
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

double BMW::getFuelCapacity()
{
    return this->fuelCapacity;
}

double BMW::getFuelConsumption()
{
    return this->fuelConsumption;
}

char* BMW::getName()
{
    return this->name;
}