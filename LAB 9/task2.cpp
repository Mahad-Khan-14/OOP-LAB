#include "iostream"
using namespace std;

class MenuItem
{
protected:
    string Dishname;
    double price;

public:
    MenuItem(string n, double p) : Dishname(n), price(p) {};

    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    virtual ~MenuItem() {};
};

class Appetizer : public MenuItem
{
public:
    Appetizer(string n, double p) : MenuItem(n, p) {}

    void prepare()
    {
        cout << "Appetizer Dish: " << Dishname << " preparing!!" << endl;
    }

    void showDetails()
    {
        cout << "Appetizer Dish Details: " << endl;
        cout << "Appetizer Dish: " << Dishname << endl
             << "Dish Price: " << price << endl;
    }
};

class MainCourse : public MenuItem
{
public:
    MainCourse(string n, double p) : MenuItem(n, p) {}

    void prepare()
    {
        cout << "MainCourse Dish: " << Dishname << " preparing!!" << endl;
    }

    void showDetails()
    {
        cout << "MainCourse Dish Details: " << endl;
        cout << "MainCourse Dish: " << Dishname << endl
             << "Dish Price: " << price << endl;
    }
};

int main()
{
    MenuItem *MenuItems[2];
    MenuItems[0] = new Appetizer("Samosa", 120);
    MenuItems[1] = new MainCourse("Biryani", 240);

    for (int i = 0; i < 2; i++)
    {
        MenuItems[i]->prepare();
        MenuItems[i]->showDetails();
    }

    for (int i = 0; i < 2; i++)
    {
        delete MenuItems[i];
    }

    return 0;
}