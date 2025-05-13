#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception
{
};
class OverCapacityException : public exception
{
};

template <typename T>
class InventoryItem
{
    T stock;
    T maxStock;

public:
    InventoryItem(T max) : maxStock(max), stock(0) {}

    void setStock(T value)
    {
        if (value < 0)
            throw NegativeStockException();
        if (value > maxStock)
            throw OverCapacityException();

        stock = value;
    }

    T getStock() const
    {
        return stock;
    }
};

int main()
{
    InventoryItem<int> item(100);

    try
    {
        cout << "Attempting to set stock to -5...\n";
        item.setStock(-5);
    }
    catch (const NegativeStockException &e)
    {
        cout << "Caught NegativeStockException what(): " << e.what() << endl;
    }

    try
    {
        cout << "\nAttempting to set stock to 120 (max 100)...\n";
        item.setStock(120);
    }
    catch (const OverCapacityException &e)
    {
        cout << "Caught OverCapacityException what(): " << e.what() << endl;
    }

    return 0;
}
