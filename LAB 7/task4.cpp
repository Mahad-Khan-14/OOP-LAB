#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string c, string addr = "")
        : name(n), age(a), contactNumber(c), address(addr) {}

    virtual void displayInfo()
    {
        cout << "Name: " << name << ", Age: " << age << ", Contact: " << contactNumber;
        if (!address.empty())
            cout << ", Address: " << address;
        cout << endl;
    }

    virtual ~Person() {}
};

class Patient : public Person
{
private:
    int patientID;
    string medicalHistory;

public:
    Patient(string n, int a, string c, int id, string history)
        : Person(n, a, c), patientID(id), medicalHistory(history) {}

    void displayInfo() override
    {
        cout << "Patient ID: " << patientID << ", ";
        Person::displayInfo();
        cout << "Medical History: " << medicalHistory << endl;
    }

    string getName() { return name; } 
};

class Doctor : public Person
{
private:
    string specialization;
    double consultationFee;
    string patientsList[10];
    int patientCount;

public:
    Doctor(string n, int a, string c, string spec, double fee)
        : Person(n, a, c), specialization(spec), consultationFee(fee), patientCount(0) {}

    void addPatient(Patient &p) 
    {
        if (patientCount < 10)
        {
            patientsList[patientCount++] = p.getName();
        }
        else
        {
            cout << "Cannot add more patients, list is full!\n";
        }
    }

    void displayInfo() override
    {
        cout << "Doctor ";
        Person::displayInfo();
        cout << "Specialization: " << specialization << ", Consultation Fee: $" << consultationFee << endl;
        cout << "Patients List: ";
        for (int i = 0; i < patientCount; i++)
            cout << patientsList[i] << ", ";
        cout << endl;
    }
};

class Nurse : public Person
{
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string c, string ward, string shift)
        : Person(n, a, c), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override
    {
        cout << "Nurse ";
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << ", Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person
{
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string c, string dept, double sal)
        : Person(n, a, c), department(dept), salary(sal) {}

    void displayInfo() override
    {
        cout << "Administrator ";
        Person::displayInfo();
        cout << "Department: " << department << ", Salary: $" << salary << endl;
    }
};

int main()
{
    const int numPeople = 4;
    Person *people[numPeople];

    Patient *p1 = new Patient("Alice", 30, "123-456", 101, "Diabetes");
    Doctor *d1 = new Doctor("Dr. Smith", 45, "987-654", "Cardiology", 150);
    people[0] = p1;
    people[1] = d1;
    people[2] = new Nurse("Nancy", 35, "555-333", "ICU", "Night Shift");
    people[3] = new Administrator("Robert", 50, "777-888", "HR", 5000);

    d1->addPatient(*p1);

    cout << "Hospital Management System:\n";
    for (int i = 0; i < numPeople; i++)
    {
        people[i]->displayInfo();
        cout << "--------------------------\n";
    }

    for (int i = 0; i < numPeople; i++)
    {
        delete people[i];
    }

    return 0;
}
