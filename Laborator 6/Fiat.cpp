#define _CRT_SECURE_NO_WARNINGS
#include "Fiat.h"
#include "Weather.h"
#include <cstring>

Fiat::Fiat()
{
    fuelCapacity = 45;
    fuelConsumption = 4.3;
    avgSpeedRain = 68;
    avgSpeedSnow = 59;
    avgSpeedSun = 87;
    name = new char[5];
    strcpy(this->name, "Fiat");
};

double Fiat::getAvgSpeed(Weather weather)
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

double Fiat::getFuelCapacity()
{
    return this->fuelCapacity;
}

double Fiat::getFuelConsumption()
{
    return this->fuelConsumption;
}

char* Fiat::getName()
{
    return this->name;
}