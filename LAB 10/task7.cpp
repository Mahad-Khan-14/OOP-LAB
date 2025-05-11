#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream sensorFile;

    sensorFile.open("sensor_log.txt");
    if (!sensorFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string data1 = "Sensor 1: 25.5 C\n";
    string data2 = "Sensor 2: 98.1 %RH\n";

    sensorFile << data1;
    cout << "Position after writing data1: " << sensorFile.tellp() << endl;

    sensorFile << data2;
    cout << "Position after writing data2: " << sensorFile.tellp() << endl;

    sensorFile.close();

    return 0;
}
