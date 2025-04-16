#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int productID;
    string name;
    int quantity;
    float price;
};

int main()
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product *inventory = new Product[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter details for product " << i + 1 << ":\n";
        cout << "Product ID: ";
        cin >> inventory[i].productID;
        cin.ignore();

        cout << "Name: ";
        getline(cin, inventory[i].name);

        cout << "Quantity: ";
        cin >> inventory[i].quantity;

        cout << "Price: ";
        cin >> inventory[i].price;
    }

    float totalValue = 0;
    for (int i = 0; i < n; ++i)
    {
        totalValue += inventory[i].quantity * inventory[i].price;
    }

    cout << "\nInventory Summary:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Product ID: " << inventory[i].productID
             << ", Name: " << inventory[i].name
             << ", Quantity: " << inventory[i].quantity
             << ", Price: " << inventory[i].price << endl;
    }

    cout << "\nTotal Inventory Value: $" << totalValue << endl;

    delete[] inventory;

    return 0;
}
