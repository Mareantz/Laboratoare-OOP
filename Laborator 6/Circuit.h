#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
    Car** cars;
    double length;
    int numberOfCars;
    Weather weather;
public:
    const int MAX_CARS = 10;
    Circuit();
    ~Circuit();
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};