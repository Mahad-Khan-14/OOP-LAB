#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool stat) : deviceID(id), status(stat) {}

    virtual void displayDetails()
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
    }
};

class SmartPhone : virtual public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int id, bool stat, float size)
        : Device(id, stat), screenSize(size) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool stat, bool monitor)
        : Device(id, stat), heartRateMonitor(monitor) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Available" : "Not Available") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
private:
    int stepCounter;

public:
    SmartWearable(int id, bool stat, float size, bool monitor, int steps)
        : Device(id, stat), SmartPhone(id, stat, size), SmartWatch(id, stat, monitor), stepCounter(steps) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Available" : "Not Available") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main()
{
    SmartWearable wearable(101, true, 5.5, true, 10000);

    cout << "Smart Wearable Device Details:\n";
    wearable.displayDetails();

    return 0;
}
