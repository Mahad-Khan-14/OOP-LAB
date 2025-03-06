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

    bool checkAvailability() const
    {
        return isAvailable;
    }

    double applyDiscount(int rentalDays) const
    {
        double discount = 0.0;

        if (rentalDays > 10)
        {
            discount = 0.10; // 10% discount for more than 10 days
        }
        else if (rentalDays > 5)
        {
            discount = 0.05; // 5% discount for more than 5 days
        }

        return rentalPrice * rentalDays * (1 - discount);
    }

    void rentCar(int rentalDays)
    {
        if (!isAvailable)
        {
            cout << "Car is unavailable for rent!\n";
            return;
        }

        double finalPrice = applyDiscount(rentalDays);
        cout << "Car rented successfully for " << rentalDays << " days.\n";
        cout << "Total price after discount: $" << finalPrice << endl;
        isAvailable = false;
    }

    void returnCar()
    {
        if (isAvailable)
        {
            cout << "Car is already available!\n";
        }
        else
        {
            isAvailable = true;
            cout << "Car returned successfully. It is now available for rent again.\n";
        }
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
    Car cars[] = {
        Car("Toyota", "Camry", 60.0, true),
        Car("Honda", "Civic", 50.0, true),
        Car("Ford", "Mustang", 100.0, true)};

    int numCars = sizeof(cars) / sizeof(cars[0]);

    for (int i = 0; i < numCars; i++)
    {
        cout << "\nCar " << i + 1 << ":";
        cars[i].displayCarDetails();
    }

    int choice, days;
    cout << "\nEnter the car number you want to rent (1-" << numCars << "): ";
    cin >> choice;
    if (choice < 1 || choice > numCars)
    {
        cout << "Invalid car selection!\n";
        return 1;
    }

    cout << "Enter number of rental days: ";
    cin >> days;
    cars[choice - 1].rentCar(days);
    cars[choice - 1].displayCarDetails();

    cout << "\nDo you want to return the car? (1 for Yes, 0 for No): ";
    int returnChoice;
    cin >> returnChoice;
    if (returnChoice == 1)
    {
        cars[choice - 1].returnCar();
        cars[choice - 1].displayCarDetails();
    }

    return 0;
}
