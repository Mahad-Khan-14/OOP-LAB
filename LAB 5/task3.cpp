#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    string designation;

    Employee(string _name, string _designation) : name(_name), designation(_designation) {}
};

class Project
{
private:
    Employee **employees;
    int employeeCount;
    int capacity;

public:
    string title;
    string deadline;

    Project(string _title, string _deadline, int _capacity = 5)
        : title(_title), deadline(_deadline), capacity(_capacity), employeeCount(0)
    {
        employees = new Employee *[capacity];
    }

    void addEmployee(Employee *employee)
    {
        if (employeeCount < capacity)
        {
            employees[employeeCount++] = employee;
        }
        else
        {
            cout << "Cannot add more employees to " << title << " (Capacity Reached)\n";
        }
    }

    void displayDetails() const
    {
        cout << "Project: " << title << "\nDeadline: " << deadline << "\nAssigned Employees:\n";
        for (int i = 0; i < employeeCount; i++)
        {
            cout << "- " << employees[i]->name << " (" << employees[i]->designation << ")\n";
        }
        cout << "-----------------------------------\n";
    }

    ~Project()
    {
        delete[] employees;
    }
};

int main()
{

    Employee emp1("Alice", "Software Engineer");
    Employee emp2("Bob", "Data Scientist");
    Employee emp3("Charlie", "Project Manager");

    Project proj1("AI Development", "2025-06-15", 3);
    Project proj2("Web Application", "2025-07-01", 3);

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);

    proj2.addEmployee(&emp1);
    proj2.addEmployee(&emp3);

    proj1.displayDetails();
    proj2.displayDetails();

    return 0;
}
