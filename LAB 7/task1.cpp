#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    string deviceName;
    bool status;

public:
    Device(int id, string name) : deviceID(id), deviceName(name), status(false) {}

    virtual void turnOn()
    {
        status = true;
        cout << deviceName << " is now ON.\n";
    }

    virtual void turnOff()
    {
        status = false;
        cout << deviceName << " is now OFF.\n";
    }

    virtual void displayInfo()
    {
        cout << "Device: " << deviceName << " | Status: " << (status ? "ON" : "OFF") << endl;
    }

    virtual ~Device() {}
};

class Light : public Device
{
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, int brightness, string color)
        : Device(id, name), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() override
    {
        cout << "Light [" << deviceName << "] | Brightness: " << brightnessLevel
             << " | Color Mode: " << colorMode << " | Status: " << (status ? "ON" : "OFF") << endl;
    }
};

class Thermostat : public Device
{
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int id, string name, float temp, string mod, float targetTemp)
        : Device(id, name), temperature(temp), mode(mod), targetTemperature(targetTemp) {}

    void displayInfo() override
    {
        cout << "Thermostat [" << deviceName << "] | Current Temp: " << temperature
             << "°C | Mode: " << mode << " | Target Temp: " << targetTemperature << "°C\n";
    }
};

class SecurityCamera : public Device
{
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string res, bool nightVision)
        : Device(id, name), resolution(res), recordingStatus(false), nightVisionEnabled(nightVision) {}

    void turnOn() override
    {
        status = true;
        recordingStatus = true;
        cout << "Security Camera [" << deviceName << "] is now recording.\n";
    }

    void displayInfo() override
    {
        cout << "Security Camera [" << deviceName << "] | Resolution: " << resolution
             << " | Night Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled")
             << " | Recording: " << (recordingStatus ? "ON" : "OFF") << endl;
    }
};

class SmartPlug : public Device
{
private:
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, float power, int timer)
        : Device(id, name), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override
    {
        status = false;
        cout << "Smart Plug [" << deviceName << "] is turned OFF. Power consumption logged: "
             << powerConsumption << "W\n";
    }

    void displayInfo() override
    {
        cout << "Smart Plug [" << deviceName << "] | Power: " << powerConsumption
             << "W | Timer: " << timerSetting << " mins | Status: " << (status ? "ON" : "OFF") << endl;
    }
};

int main()
{
    const int numDevices = 4;
    Device *devices[numDevices];

    devices[0] = new Light(101, "Living Room Light", 75, "Warm White");
    devices[1] = new Thermostat(102, "Bedroom Thermostat", 22.5, "Cooling", 24.0);
    devices[2] = new SecurityCamera(103, "Front Door Camera", "1080p", true);
    devices[3] = new SmartPlug(104, "TV Plug", 120.5, 60);

    cout << "Smart Home Automation System:\n";
    for (int i = 0; i < numDevices; i++)
    {
        devices[i]->turnOn();
        devices[i]->displayInfo();
        cout << "------------------------\n";
    }

    devices[3]->turnOff();

    for (int i = 0; i < numDevices; i++)
    {
        delete devices[i];
    }

    return 0;
}
