/*
The goal of this task is to:

Record the AQI values for 4 cities over 28 days (4 weeks).

Calculate the overall monthly average AQI for each city.

Identify the city with the most improved air quality by comparing the weekly averages of the first and last weeks.
*/

#include <iostream>
using namespace std;

int main()
{
    const int CITIES = 4;
    const int WEEKS = 4;
    const int DAYS_PER_WEEK = 7;
    const int TOTAL_DAYS = WEEKS * DAYS_PER_WEEK;

    int aqi[CITIES][TOTAL_DAYS];
    string cities[CITIES] = {"City A", "City B", "City C", "City D"};

    for (int i = 0; i < CITIES; i++)
    {
        cout << "Enter AQI values for " << cities[i] << " over 28 days:" << endl;
        for (int j = 0; j < TOTAL_DAYS; j++)
        {
            cout << "Day " << j + 1 << ": ";
            cin >> aqi[i][j];
        }
    }

    float monthlyAverages[CITIES] = {0};
    for (int i = 0; i < CITIES; i++)
    {
        for (int j = 0; j < TOTAL_DAYS; j++)
        {
            monthlyAverages[i] += aqi[i][j];
        }
        monthlyAverages[i] /= TOTAL_DAYS;
    }

    cout << "\nOverall Monthly Average AQI for Each City:" << endl;
    for (int i = 0; i < CITIES; i++)
    {
        cout << cities[i] << ": " << monthlyAverages[i] << endl;
    }

    float firstWeekAverages[CITIES] = {0};
    float lastWeekAverages[CITIES] = {0};

    for (int i = 0; i < CITIES; i++)
    {

        for (int j = 0; j < DAYS_PER_WEEK; j++)
        {
            firstWeekAverages[i] += aqi[i][j];
        }
        firstWeekAverages[i] /= DAYS_PER_WEEK;

        for (int j = TOTAL_DAYS - DAYS_PER_WEEK; j < TOTAL_DAYS; j++)
        {
            lastWeekAverages[i] += aqi[i][j];
        }
        lastWeekAverages[i] /= DAYS_PER_WEEK;
    }

    int mostImprovedCityIndex = 0;
    float largestDrop = firstWeekAverages[0] - lastWeekAverages[0];

    for (int i = 1; i < CITIES; i++)
    {
        float drop = firstWeekAverages[i] - lastWeekAverages[i];
        if (drop > largestDrop)
        {
            largestDrop = drop;
            mostImprovedCityIndex = i;
        }
    }

    cout << "\nCity with the most improved air quality: " << cities[mostImprovedCityIndex] << endl;
    cout << "Improvement (drop in AQI): " << largestDrop << endl;

    return 0;
}