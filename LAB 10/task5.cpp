#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
using namespace std;

class cardealer
{
private:
    string filename;

public:
    cardealer(const string &name) : filename(name) {}

    void readdata()
    {
        ifstream in(filename);
        string line;
        cout << "Reading file " << filename << endl;
        if (in.is_open())
        {
            while (getline(in, line))
            {
                if (line.empty() || line.substr(0, 2) == "//")
                {
                    continue;
                }

                cout << "Original Line: " << line << endl;

                istringstream str(line);

                string type, id, name, stryear, extra, cert;
                getline(str, type, ',');
                getline(str, id, ',');
                getline(str, name, ',');
                getline(str, stryear, ',');
                getline(str, extra, ',');
                getline(str, cert, ',');

                int year = stoi(stryear);

                cout << "Type: " << type << endl;
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Year: " << year << endl;
                cout << "Extra Data: " << extra << endl;
                cout << "Certification: " << cert << endl;
                // cout << "-----------------------------\n";

                size_t colonpos = extra.find(':');
                if (colonpos != string::npos)
                {
                    string valuestr = extra.substr(colonpos + 1);

                    if (type == "AutonomousCar")
                    {
                        float softwareversion = stof(valuestr);
                        cout << "Software Version (float) for ID " << id << ": " << softwareversion << endl;
                    }
                    else if (type == "ElectricVehicle")
                    {
                        int batteryCapacity = stoi(valuestr);
                        cout << "Battery Capacity (int) for ID " << id << ": " << batteryCapacity << " mAh" << endl;
                    }
                    else if (type == "HybridTruck")
                    {
                        size_t cargoColon = extra.find("Cargo:");
                        size_t pipePos = extra.find('|');
                        size_t batteryColon = extra.find("Battery:");

                        if (cargoColon != string::npos && pipePos != string::npos && batteryColon != string::npos)
                        {

                            size_t cargoStart = cargoColon + 6; // Length of "Cargo:"
                            string cargoStr = extra.substr(cargoStart, pipePos - cargoStart);
                            int cargo = stoi(cargoStr);

                            size_t batteryStart = batteryColon + 8; // Length of "Battery:"
                            string batteryStr = extra.substr(batteryStart);
                            int battery = stoi(batteryStr);

                            cout << "Cargo Capacity: " << cargo << " kg" << endl;
                            cout << "Battery Capacity: " << battery << " mAh" << endl;
                        }
                        else
                        {
                            cout << "Error parsing HybridTruck extra data.\n";
                        }
                    }
                    else
                    {
                        cout << "Unknown vehicle type: " << type << endl;
                    }

                    cout << "-----------------------------\n";
                }
            }
            in.close();
        }
        else
        {
            cout << "File could not be able to open for reading" << endl;
        }
    }
};

int main()
{
    cardealer vehicle("vehicle.txt");
    vehicle.readdata();
    return 0;
}