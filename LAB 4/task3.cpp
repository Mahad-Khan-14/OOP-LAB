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

public:
    Car(string b, string m, double price, bool availability)
        : brand(b), model(m), rentalPrice(price), isAvailable(availability) {}

    Car(const Car &other)
        : brand(other.brand), model(other.model),
          rentalPrice(other.rentalPrice), isAvailable(other.isAvailable)
    {
        cout << "Copy Constructor: A copy of " << brand << " " << model << " has been created.\n";
    }

    ~Car()
    {
        cout << "Destructor: " << brand << " " << model << " is being removed from memory.\n";
    }

    void updateCarDetails(string b, string m, double price, bool availability)
    {
        brand = b;
        model = m;
        rentalPrice = price;
        isAvailable = availability;
    }

    void displayCarDetails() const
    {
        cout << "\nCar Details:\n";
        cout << "Brand: " << brand << ", Model: " << model
             << ", Rental Price per day: $" << rentalPrice
             << ", Availability: " << (isAvailable ? "Available" : "Rented") << endl;
    }
};

int main()
{
    Car originalCar("Toyota", "Corolla", 50.0, true);
    cout << "\nOriginal Car Created:";
    originalCar.displayCarDetails();

    Car copiedCar = originalCar;
    cout << "\nCopied Car Created:";
    copiedCar.displayCarDetails();

    originalCar.updateCarDetails("Honda", "Civic", 60.0, false);
    cout << "\nModified Original Car:";
    originalCar.displayCarDetails();

    cout << "\nCopied Car After Modification (Should Remain Unchanged):";
    copiedCar.displayCarDetails();

    return 0;
}
