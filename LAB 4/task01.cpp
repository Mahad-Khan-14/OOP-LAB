/*
    M. Mahad Khan
    24K-0961
    BCS-2C
    Lab4 Task
*/

#include <iostream>

using namespace std;

class Car
{
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;

public:
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true) {}

    Car(string b, string m, double price) : brand(b), model(m), rentalPrice(price), isAvailable(true) {}

    void updateCarDetails(string b, string m, double price)
    {
        brand = b;
        model = m;
        rentalPrice = price;
    }

    bool checkAvailability() const
    {
        return isAvailable;
    }

    void rentCar()
    {
        if (isAvailable)
        {
            isAvailable = false;
            cout << "Car rented successfully!" << endl;
        }
        else
        {
            cout << "Car is already rented!" << endl;
        }
    }

    void displayCarDetails() const
    {
        cout << "Brand: " << brand << ", Model: " << model
             << ", Rental Price: $" << rentalPrice
             << ", Availability: " << (isAvailable ? "Available" : "Rented") << endl;
    }
};

int main()
{
    Car car1;
    car1.displayCarDetails();

    cout << "\nUpdating car details...\n";
    car1.updateCarDetails("Toyota", "Corolla", 50.0);
    car1.displayCarDetails();

    cout << "\nChecking availability and renting the car...\n";
    car1.rentCar();
    car1.displayCarDetails();

    cout << "\nTrying to rent the car again...\n";
    car1.rentCar();
    return 0;
}
