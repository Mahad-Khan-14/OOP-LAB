#include <iostream>
#include <string>

using namespace std;

#define MAX_DOCTORS 10

class Doctor
{
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor() {}
    Doctor(string n, string spec, int exp) : name(n), specialization(spec), experience(exp) {}

    void display() const
    {
        cout << "Doctor Name: " << name << ", Specialization: " << specialization
             << ", Experience: " << experience << " years" << endl;
    }

    bool isEmpty() const
    {
        return name.empty();
    }
};

class Hospital
{
private:
    string hospitalName;
    Doctor doctors[MAX_DOCTORS];
    int doctorCount;

public:
    Hospital(string name) : hospitalName(name), doctorCount(0) {}

    void addDoctor(const Doctor &doc)
    {
        if (doctorCount < MAX_DOCTORS)
        {
            doctors[doctorCount] = doc;
            doctorCount++;
        }
        else
        {
            cout << "Hospital doctor limit reached!" << endl;
        }
    }

    void display() const
    {
        cout << "Hospital: " << hospitalName << endl;
        cout << "Doctors currently working here:" << endl;
        for (int i = 0; i < doctorCount; i++)
        {
            doctors[i].display();
        }
    }
};

int main()
{

    Doctor doc1("Dr. Smith", "Cardiologist", 10);
    Doctor doc2("Dr. Jane", "Neurologist", 8);
    Doctor doc3("Dr. Mark", "Pediatrician", 5);

    Hospital hospital("City General Hospital");

    hospital.addDoctor(doc1);
    hospital.addDoctor(doc2);
    hospital.addDoctor(doc3);

    hospital.display();

    return 0;
}
