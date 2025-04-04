#include "iostream"
using namespace std;

class Employee
{
public:
    string name;
    float salary;

    Employee(string n, float s) : name(n), salary(s) {};
    virtual void displayDetails()
    {
        cout << "Name: " << name << endl
             << "Salary: " << salary << endl;
    }
};

class Manager : public Employee
{
public:
    float bonus;

    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}

    void displayDetails()
    {
        cout << "Manager: " << name << endl
             << "Salary: " << salary << endl
             << "Bonus: " << bonus << endl;
    }
};

int main()
{
    Manager m1("Mahad", 200500, 20000);
    m1.displayDetails();
    return 0;
}