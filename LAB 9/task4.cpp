#include "iostream"
using namespace std;

class WeatherSensor
{
protected:
    string Reading;

public:
    WeatherSensor(string r) : Reading(r) {};

    virtual void readData() = 0;
    virtual void DisplayReport() = 0;
    virtual ~WeatherSensor() {};
};

class Thermometer : public WeatherSensor
{
public:
    Thermometer(string r) : WeatherSensor(r) {}

    void readData()
    {
        cout << "Temperature According to Thermometer: " << Reading << endl;
    }

    void DisplayReport()
    {
        cout << "Thermometer Device Report: " << endl;
        cout << "Temperature: " << Reading << endl;
    }
};

class Barometer : public WeatherSensor
{
public:
    Barometer(string r) : WeatherSensor(r) {}

    void readData()
    {
        cout << "Pressure According to Barometer: " << Reading << endl;
    }

    void DisplayReport()
    {
        cout << "Barometer Device Report: " << endl;
        cout << "Pressure: " << Reading << endl;
    }
};

int main()
{
    WeatherSensor *sensors[2];
    sensors[0] = new Thermometer("38^C");
    sensors[1] = new Barometer("100KPA");

    for (int i = 0; i < 2; i++)
    {
        sensors[i]->readData();
        sensors[i]->DisplayReport();
    }

    for (int i = 0; i < 2; i++)
    {
        delete sensors[i];
    }

    return 0;
}