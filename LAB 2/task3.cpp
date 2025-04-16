#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    float hoursWorked;
    float hourlyRate;
};

int main()
{
    int numEmployees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee *employees = new Employee[numEmployees];

    cin.ignore();

    for (int i = 0; i < numEmployees; ++i)
    {
        cout << "\nEnter details for Employee " << i + 1 << ":\n";

        cout << "Name: ";
        getline(cin, employees[i].name);

        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;

        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;

        cin.ignore();
    }

    cout << "\nEmployee Salary Details:\n";
    for (int i = 0; i < numEmployees; ++i)
    {
        float totalSalary = employees[i].hoursWorked * employees[i].hourlyRate;
        cout << "\nName: " << employees[i].name
             << "\nHours Worked: " << employees[i].hoursWorked
             << "\nHourly Rate: " << employees[i].hourlyRate
             << "\nTotal Salary: " << totalSalary << endl;
    }

    delete[] employees;

    return 0;
}
