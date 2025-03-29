#include <iostream>
#include <string>

using namespace std;

class AlarmSystem
{
private:
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {}

    void display() const
    {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome
{
private:
    string homeName;
    AlarmSystem alarm;

public:
    SmartHome(string name, string securityLevel) : homeName(name), alarm(securityLevel) {}

    void display() const
    {
        cout << "Smart Home: " << homeName << endl;
        alarm.display();
    }
};

int main()
{

    SmartHome home1("Luxury Villa", "High");
    SmartHome home2("Modern Apartment", "Medium");

    home1.display();
    home2.display();

    return 0;
}
