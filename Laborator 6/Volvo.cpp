#define _CRT_SECURE_NO_WARNINGS
#include "Volvo.h"
#include "Weather.h"
#include <cstring>


Volvo::Volvo()
{
    fuelCapacity = 60;
    fuelConsumption = 8;
    avgSpeedRain = 80;
    avgSpeedSnow = 60;
    avgSpeedSun = 100;
    name = new char[6];
    strcpy(this->name, "Volvo");
};

double Volvo::getAvgSpeed(Weather weather)
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

double Volvo::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Volvo::getFuelConsumption()
{
    return this->fuelConsumption;
}

char* Volvo::getName()
{
    return this->name;
}