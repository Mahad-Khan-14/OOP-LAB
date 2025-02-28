/*
The goal of this task is to:

- Identify days where the AQI exceeded 150 for any city.

- Display these critical pollution days for each city.
*/

#include <iostream>
using namespace std;

int main()
{
    int CITIES;
    cout << "Enter the no. of cities:" << endl;
    cin >> CITIES;

    int DAYS;
    cout << "Enter the no. of days:" << endl;
    cin >> DAYS;

    int aqi[CITIES][DAYS];

    string cities[CITIES];
    for (int i = 0; i < CITIES; i++)
    {
        cout << "Enter city: " << i + 1 << endl;
        cin >> cities[i];
    }

    for (int i = 0; i < CITIES; i++)
    {
        cout << "Enter AQI values for " << cities[i] << " over " << DAYS << " days:" << endl;
        for (int j = 0; j < DAYS; j++)
        {
            cout << "Day " << j + 1 << ": ";
            cin >> aqi[i][j];
        }
    }

    for (int i = 0; i < CITIES; i++)
    {
        cout << "Critical pollution days for " << cities[i] << ": ";
        bool hasCriticalDays = false;
        for (int j = 0; j < DAYS; j++)
        {
            if (aqi[i][j] > 150)
            {
                cout << "Day " << j + 1 << " ";
                hasCriticalDays = true;
            }
        }
        if (!hasCriticalDays)
        {
            cout << "None";
        }
        cout << endl;
    }

    return 0;
}