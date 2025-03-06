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
    string registrationNumber;
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;
    double totalRevenue;

public:
    Car(string regNum, string brand, string model, double rentalPrice, bool isAvailable = true)
        : registrationNumber(regNum), brand(brand), model(model), rentalPrice(rentalPrice),
          isAvailable(isAvailable), totalRevenue(0.0) {}

    void rentCar(int days)
    {
        if (!isAvailable)
        {
            cout << "Car " << registrationNumber << " is already rented. Cannot proceed.\n";
            return;
        }

        totalRevenue += rentalPrice * days;
        isAvailable = false;
        cout << "Car " << registrationNumber << " rented for " << days << " days. Revenue updated.\n";
    }

    void displayCarDetails() const
    {
        cout << "Car ID: " << registrationNumber << " | " << brand << " " << model << "\n";
        cout << "Price per day: $" << rentalPrice << " | Status: "
             << (isAvailable ? "Available" : "Rented") << "\n";
        cout << "Total Revenue: $" << totalRevenue << "\n";
        cout << "-------------------------------------------------\n";
    }
};

int main()
{

    Car car1("CAR123", "Toyota", "Corolla", 50.0);
    Car car2("CAR456", "Honda", "Civic", 60.0);

    car1.displayCarDetails();
    car2.displayCarDetails();

    car1.rentCar(5);

    car1.displayCarDetails();
    car2.displayCarDetails();

    return 0;
}
