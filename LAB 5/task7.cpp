#include <iostream>
#include <string>

using namespace std;

#define MAX_PRODUCTS 10

class Product
{
public:
    int id;
    string name;
    int quantity;

    Product() {}

    Product(int i, string n, int q) : id(i), name(n), quantity(q) {}

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Warehouse
{
private:
    Product products[MAX_PRODUCTS];
    int productCount;

public:
    Warehouse() : productCount(0) {}

    void addProduct(int id, string name, int quantity)
    {
        if (productCount < MAX_PRODUCTS)
        {
            products[productCount] = Product(id, name, quantity);
            productCount++;
        }
        else
        {
            cout << "Inventory is full!\n";
        }
    }

    void sortProducts()
    {
        for (int i = 0; i < productCount - 1; i++)
        {
            for (int j = 0; j < productCount - i - 1; j++)
            {
                if (products[j].name > products[j + 1].name)
                {
                    swap(products[j], products[j + 1]);
                }
            }
        }
    }

    void searchProduct(int id)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (products[i].id == id)
            {
                cout << "Product found:\n";
                products[i].display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found.\n";
    }

    void displayProducts()
    {
        cout << "Product Inventory:\n";
        for (int i = 0; i < productCount; i++)
        {
            products[i].display();
        }
    }
};

int main()
{
    Warehouse warehouse;

    warehouse.addProduct(101, "Laptop", 5);
    warehouse.addProduct(102, "Chair", 10);
    warehouse.addProduct(103, "Apple", 20);
    warehouse.addProduct(104, "Table", 7);

    warehouse.sortProducts();

    warehouse.displayProducts();

    int searchID;
    cout << "\nEnter product ID to search: ";
    cin >> searchID;
    warehouse.searchProduct(searchID);

    return 0;
}
