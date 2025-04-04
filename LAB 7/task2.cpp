#include <iostream>
using namespace std;

class Product
{
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock = 0)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual double calculateTotalPrice(int quantity)
    {
        return price * quantity;
    }

    virtual void applyDiscount()
    {
        cout << productName << ": No discount applied.\n";
    }

    virtual void displayProductInfo()
    {
        cout << "Product ID: " << productID << ", Name: " << productName
             << ", Price: $" << price << ", Stock: " << stockQuantity << endl;
    }

    double operator+(const Product &other)
    {
        return this->price + other.price;
    }

    friend ostream &operator<<(ostream &out, const Product &p)
    {
        out << "Product: " << p.productName << " | Price: $" << p.price;
        return out;
    }

    virtual ~Product() {}
};

class Electronics : public Product
{
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string br)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(br) {}

    void displayProductInfo() override
    {
        cout << "Electronics: " << productName << " | Brand: " << brand
             << " | Warranty: " << warrantyPeriod << " years | Price: $" << price << endl;
    }
};

class Clothing : public Product
{
private:
    string size, color, fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fabric)
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}

    void applyDiscount() override
    {
        price *= 0.9;
        cout << productName << ": Seasonal discount applied. New Price: $" << price << endl;
    }

    void displayProductInfo() override
    {
        cout << "Clothing: " << productName << " | Size: " << size << " | Color: " << color
             << " | Fabric: " << fabricMaterial << " | Price: $" << price << endl;
    }
};

class FoodItem : public Product
{
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string expiry, int cal)
        : Product(id, name, p, stock), expirationDate(expiry), calories(cal) {}

    double calculateTotalPrice(int quantity) override
    {
        double total = price * quantity;
        if (quantity > 5)
            total *= 0.85;
        return total;
    }

    void displayProductInfo() override
    {
        cout << "Food Item: " << productName << " | Expiry: " << expirationDate
             << " | Calories: " << calories << " kcal | Price: $" << price << endl;
    }
};

class Book : public Product
{
private:
    string author, genre;

public:
    Book(int id, string name, double p, int stock, string a, string g)
        : Product(id, name, p, stock), author(a), genre(g) {}

    void displayProductInfo() override
    {
        cout << "Book: " << productName << " | Author: " << author
             << " | Genre: " << genre << " | Price: $" << price << endl;
    }
};

int main()
{
    const int numProducts = 4;
    Product *products[numProducts];

    products[0] = new Electronics(101, "Laptop", 1200, 10, 2, "Dell");
    products[1] = new Clothing(102, "T-Shirt", 25, 50, "M", "Blue", "Cotton");
    products[2] = new FoodItem(103, "Cereal", 10, 100, "12-12-2025", 150);
    products[3] = new Book(104, "The C++ Guide", 45, 20, "Bjarne Stroustrup", "Programming");

    cout << "E-Commerce Order Management System:\n";
    for (int i = 0; i < numProducts; i++)
    {
        products[i]->displayProductInfo();
        products[i]->applyDiscount();
        cout << "--------------------------\n";
    }

    double totalPrice = *products[0] + *products[1];
    cout << "Total Price (Laptop + T-Shirt): $" << totalPrice << endl;

    cout << *products[3] << endl;

    for (int i = 0; i < numProducts; i++)
    {
        delete products[i];
    }

    return 0;
}
