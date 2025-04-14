#include <iostream>
#include <string>
using namespace std;

class InventoryManager;

class Car
{
private:
    string model;
    double price;

public:
    Car(string m = "", double p = 0.0) : model(m), price(p) {}

    friend class InventoryManager;

    friend void comparePrice(const Car &car1, const Car &car2);
};

class InventoryManager
{
public:
    void updatePrice(Car &car, double newPrice)
    {
        car.price = newPrice;
    }

    void displayCar(const Car &car)
    {
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;
    }
};

void comparePrice(const Car &car1, const Car &car2)
{
    cout << "\nComparing Cars:\n";
    if (car1.price > car2.price)
    {
        cout << car1.model << " is more expensive than " << car2.model << ".\n";
    }
    else if (car2.price > car1.price)
    {
        cout << car2.model << " is more expensive than " << car1.model << ".\n";
    }
    else
    {
        cout << car1.model << " and " << car2.model << " have the same price.\n";
    }
}

int main()
{

    Car car1("Toyota Corolla", 30000);
    Car car2("Honda Civic", 28000);

    InventoryManager manager;

    cout << "Original Car Details:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car1, 31000);
    manager.updatePrice(car2, 31000);

    cout << "\nUpdated Car Details:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    comparePrice(car1, car2);

    return 0;
}
