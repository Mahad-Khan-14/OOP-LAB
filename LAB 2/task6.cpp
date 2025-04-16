#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    string rollNumber;
    float marks[3];
    float average;
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student *students = new Student[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);

        cout << "Roll Number: ";
        cin >> students[i].rollNumber;

        cout << "Enter marks for 3 subjects:\n";
        float total = 0;
        for (int j = 0; j < 3; ++j)
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
            total += students[i].marks[j];
        }
        students[i].average = total / 3.0;
    }

    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Marks: ";
        for (int j = 0; j < 3; ++j)
        {
            cout << students[i].marks[j] << " ";
        }
        cout << "\nAverage Marks: " << students[i].average << "\n\n";
    }

    delete[] students;

    return 0;
}
