#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include "Weather.h"
#include <cstring>

Seat::Seat()
{
    fuelCapacity = 53;
    fuelConsumption = 7;
    avgSpeedRain = 75;
    avgSpeedSnow = 65;
    avgSpeedSun = 130;
    name = new char[5];
    strcpy(this->name, "Seat");
};

double Seat::getAvgSpeed(Weather weather)
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

double Seat::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Seat::getFuelConsumption()
{
    return this->fuelConsumption;
}

char* Seat::getName()
{
    return this->name;
}