#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    float fuelCapacity;
    float currentFuelLevel;
    float fuelConsumptionRate;

public:
    Car(string b, string m, float capacity, float currentFuel, float rate)
        : brand(b), model(m), fuelCapacity(capacity), currentFuelLevel(currentFuel), fuelConsumptionRate(rate) {}

    void drive(float km)
    {
        float fuelNeeded = km * fuelConsumptionRate;

        if (fuelNeeded > currentFuelLevel)
        {
            cout << "Not enough fuel to drive " << km << " km. Please refuel.\n";
        }
        else
        {
            currentFuelLevel -= fuelNeeded;
            cout << "Drove " << km << " km. Fuel used: " << fuelNeeded << " L\n";
            checkFuelStatus();
        }
    }

    void refuel(float liters)
    {
        if (liters <= 0)
        {
            cout << "Invalid refuel amount.\n";
            return;
        }

        if (currentFuelLevel + liters > fuelCapacity)
        {
            cout << "Tank overflow! Can only refuel up to " << (fuelCapacity - currentFuelLevel) << " L\n";
        }
        else
        {
            currentFuelLevel += liters;
            cout << "Refueled " << liters << " L. Current fuel: " << currentFuelLevel << " L\n";
        }
    }

    void checkFuelStatus()
    {
        cout << "Fuel Level: " << currentFuelLevel << " L / " << fuelCapacity << " L\n";
        if (currentFuelLevel < 0.1 * fuelCapacity)
        {
            cout << "Warning: Fuel level is low!\n";
        }
    }
};

int main()
{
    Car ZoyaCar("Toyota", "Corolla", 40.0, 10.0, 0.1);

    ZoyaCar.checkFuelStatus();
    ZoyaCar.drive(50);
    ZoyaCar.refuel(20);
    ZoyaCar.drive(300);
    ZoyaCar.checkFuelStatus();

    return 0;
}