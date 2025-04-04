#include <iostream>
using namespace std;

class Vehicle
{
public:
    string brand;
    int speed;

    Vehicle(string b, int s) : brand(b), speed(s) {}

    virtual void displayDetails()
    {
        cout << "Brand: " << brand << endl
             << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle
{
public:
    int seats;

    Car(string b, int s, int seatCount) : Vehicle(b, s), seats(seatCount) {}

    virtual void displayDetails()
    {
        cout << "Brand: " << brand << endl
             << "Speed: " << speed << " km/h" << endl
             << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car
{
public:
    int batteryLife;

    ElectricCar(string b, int s, int seatCount, int bLife)
        : Car(b, s, seatCount), batteryLife(bLife) {}

    void displayDetails()
    {
        cout << "Brand: " << brand << endl
             << "Speed: " << speed << " km/h" << endl
             << "Seats: " << seats << endl
             << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main()
{
    ElectricCar eCar("Tesla", 250, 5, 12);
    eCar.displayDetails();

    return 0;
}
