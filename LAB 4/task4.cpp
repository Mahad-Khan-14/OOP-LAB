/*
    M. Mahad Khan
    24K-0961
    BCS-2C
    Lab4 Task
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;
    double totalRevenue;

public:
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true), totalRevenue(0.0) {}

    Car(string brand, string model, double rentalPrice, bool isAvailable = true)
        : brand(brand), model(model), rentalPrice(rentalPrice), isAvailable(isAvailable), totalRevenue(0.0) {}

    void rentCar(int days)
    {
        if (!isAvailable)
        {
            cout << "Car is already rented. Cannot proceed.\n";
            return;
        }

        this->totalRevenue += this->rentalPrice * days;
        this->isAvailable = false;
        cout << "Car rented for " << days << " days. Revenue updated.\n";
    }

    void displayRevenue() const
    {
        cout << "Total Revenue for " << brand << " " << model << ": $" << totalRevenue << endl;
    }

    void displayCarDetails() const
    {
        cout << "Car: " << brand << " " << model << " | Price: $" << rentalPrice << " per day | ";
        cout << (isAvailable ? "Available" : "Rented") << endl;
    }
};

int main()
{
    Car car1("Toyota", "Corolla", 50.0);

    car1.displayCarDetails();

    car1.rentCar(7);

    car1.displayRevenue();

    return 0;
}
