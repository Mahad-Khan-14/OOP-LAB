/*
The goal of this task is to:

Generate a visual representation of AQI levels for each city over the week.

Use * symbols to represent AQI levels, where each * represents an AQI increment of 50.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int CITIES = 4;
    const int DAYS = 7;
    int aqi[CITIES][DAYS] = {
        {50, 160, 70, 80, 90, 100, 110},
        {40, 50, 60, 170, 80, 90, 100},
        {30, 40, 50, 60, 70, 180, 90},
        {20, 30, 40, 50, 60, 70, 80}};
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};

    cout << setw(15) << left << "City";
    for (int j = 0; j < DAYS; j++)
    {
        cout << setw(10) << "Day " << j + 1;
    }
    cout << endl;

    for (int i = 0; i < CITIES; i++)
    {
        cout << setw(15) << left << cities[i];
        for (int j = 0; j < DAYS; j++)
        {
            int stars = aqi[i][j] / 50;
            cout << setw(10) << string(stars, '*');
        }
        cout << endl;
    }

    return 0;
}