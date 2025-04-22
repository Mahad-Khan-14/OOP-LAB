#include "iostream"
using namespace std;

class Patient
{
protected:
    string name, id;

public:
    Patient(string n, string i) : name(n), id(i) {};

    virtual void DisplayTreatment() = 0;
    virtual int CalculateCost() = 0;
    virtual ~Patient() {};
};

class InPatient : public Patient
{
private:
    int DaysOfAdmit;
    int ratePerDay;

public:
    InPatient(string n, string i, int days, int rate) : Patient(n, i), DaysOfAdmit(days), ratePerDay(rate) {}

    void DisplayTreatment()
    {
        cout << "InPatient Name: " << name << ", id: (" << id << ")" << endl;
        cout << "The number of Days admitted is : " << DaysOfAdmit << "," << "\n"
             << "The rate per days is: " << ratePerDay << endl;
    }

    int CalculateCost()
    {
        return DaysOfAdmit * ratePerDay;
    };
};

class OutPatient : public Patient
{
private:
    int ConsultationFee;

public:
    OutPatient(string n, string i, int fee) : Patient(n, i), ConsultationFee(fee) {}

    void DisplayTreatment()
    {
        cout << "OutPatient Name: " << name << ", id: (" << id << ")" << endl;
        cout << "The Consultaion Fee: " << ConsultationFee << endl;
    }

    int CalculateCost()
    {
        return ConsultationFee;
    };
};

int main()
{
    Patient *patients[2];
    patients[0] = new InPatient("MR.MAHAD", "14A", 10, 1200);
    patients[1] = new OutPatient("KHADIM KHAN", "11C", 1400);

    for (int i = 0; i < 2; i++)
    {
        patients[i]->DisplayTreatment();
        cout << "Cost of Treatment: " << patients[i]->CalculateCost() << "\n"
             << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete patients[i];
    }

    return 0;
}