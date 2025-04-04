#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    virtual void displayDetails()
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person
{
public:
    string subject;

    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}

    void displayDetails()
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person
{
public:
    string researchArea;

    Researcher(string n, int a, string rArea) : Person(n, a), researchArea(rArea) {}

    void displayDetails()
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher
{
public:
    int publications;

    Professor(string n, int a, string sub, string rArea, int pubs)
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, rArea), publications(pubs) {}

    void displayDetails()
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Subject: " << subject << endl
             << "Research Area: " << researchArea << endl
             << "Publications: " << publications << endl;
    }
};

int main()
{
    Professor prof("Dr. John Doe", 45, "Computer Science", "Artificial Intelligence", 30);
    prof.displayDetails();

    return 0;
}
