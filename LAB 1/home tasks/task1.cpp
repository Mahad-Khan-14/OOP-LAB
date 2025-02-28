/*
The goal of this task is to record the AQI for 4 cities over 7 days using a 2D array. The program should:

- Input the AQI values for each city and each day.

- Calculate and display the average AQI for each city over the week.

- Identify the city with the worst air quality (highest average AQI).
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

    float averages[CITIES] = {0};

    for (int i = 0; i < CITIES; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            averages[i] += aqi[i][j];
        }
        averages[i] /= DAYS;
    }

    cout << "\nAverage AQI for each city:" << endl;
    for (int i = 0; i < CITIES; i++)
    {
        cout << cities[i] << ": " << averages[i] << endl;
    }

    int worstCityIndex = 0;
    for (int i = 1; i < CITIES; i++)
    {
        if (averages[i] > averages[worstCityIndex])
        {
            worstCityIndex = i;
        }
    }
    cout << "\nCity with the worst air quality: " << cities[worstCityIndex] << endl;

    return 0;
}