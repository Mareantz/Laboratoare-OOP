#include "Circuit.h"
#include <iostream>
#include <iomanip>
using namespace std;
Circuit::Circuit()
{
    length = 0;
    numberOfCars = 0;
    weather = Weather::Sun;
    cars = new Car * [MAX_CARS];
}
Circuit::~Circuit()
{
    delete[] cars;
}
void Circuit::AddCar(Car* car)
{
    if (numberOfCars < MAX_CARS)
    {
        cars[numberOfCars] = car;
        numberOfCars++;
    }
}

void Circuit::SetLength(double length)
{
    this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
    this->weather = weather;
}

void Circuit::Race()
{
    for (int i = 0; i < numberOfCars; i++)
    {
        if (cars[i]->getFuelCapacity() >= length * cars[i]->getFuelConsumption() / 100)
        {
            double time = length / cars[i]->getAvgSpeed(weather);
            cout << cars[i]->getName() << " finished the race in " << fixed << setprecision(2) << time << " hours" << endl;
        }
    }
}

void Circuit::ShowFinalRanks()
{
    Car** tempCars = new Car * [numberOfCars];
    for (int i = 0; i < numberOfCars; i++)
    {
        tempCars[i] = cars[i];
    }
    for (int i = 0; i < numberOfCars - 1; i++)
    {
        for (int j = i + 1; j < numberOfCars; j++)
        {
            if (length / tempCars[i]->getAvgSpeed(weather) > length / tempCars[j]->getAvgSpeed(weather))
            {
                Car* tempCar = tempCars[i];
                tempCars[i] = tempCars[j];
                tempCars[j] = tempCar;
            }
        }
    }
    cout << "Final Ranks:" << endl;
    int k = 0;
    for (int i = 0; i < numberOfCars; i++)
    {
        if (tempCars[i]->getFuelCapacity() >= length * tempCars[i]->getFuelConsumption() / 100)
        {
            k++;
            cout << k << "." << tempCars[i]->getName() << endl;
        }


    }
    delete[] tempCars;
}

void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < numberOfCars; i++)
    {
        if (cars[i]->getFuelCapacity() < length * cars[i]->getFuelConsumption() / 100)
        {
            cout << cars[i]->getName() << " did not finish the race because it ran out of fuel" << endl;
        }
    }
}