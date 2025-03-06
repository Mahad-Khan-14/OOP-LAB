/*
The goal of this task is to:

Generate a detailed report summarizing the AQI data for 4 cities over 28 days.

Include weekly averages, critical pollution days, and a comparison of the highest and lowest AQI values.
*/

#include <iostream>
#include <iomanip>
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

    float weeklyAverages[CITIES][WEEKS] = {0};
    for (int i = 0; i < CITIES; i++)
    {
        for (int week = 0; week < WEEKS; week++)
        {
            for (int day = 0; day < DAYS_PER_WEEK; day++)
            {
                weeklyAverages[i][week] += aqi[i][week * DAYS_PER_WEEK + day];
            }
            weeklyAverages[i][week] /= DAYS_PER_WEEK;
        }
    }

    bool criticalDays[CITIES][TOTAL_DAYS] = {false};
    for (int i = 0; i < CITIES; i++)
    {
        for (int j = 0; j < TOTAL_DAYS; j++)
        {
            if (aqi[i][j] > 150)
            {
                criticalDays[i][j] = true;
            }
        }
    }

    int highestAQI[CITIES] = {0};
    int lowestAQI[CITIES] = {1000};
    for (int i = 0; i < CITIES; i++)
    {
        for (int j = 0; j < TOTAL_DAYS; j++)
        {
            if (aqi[i][j] > highestAQI[i])
            {
                highestAQI[i] = aqi[i][j];
            }
            if (aqi[i][j] < lowestAQI[i])
            {
                lowestAQI[i] = aqi[i][j];
            }
        }
    }

    cout << "\n===== AQI Monthly Report =====" << endl;

    cout << "\nWeekly Averages for Each City:" << endl;
    cout << setw(15) << left << "City";
    for (int week = 0; week < WEEKS; week++)
    {
        cout << setw(10) << "Week " << week + 1;
    }
    cout << endl;

    for (int i = 0; i < CITIES; i++)
    {
        cout << setw(15) << left << cities[i];
        for (int week = 0; week < WEEKS; week++)
        {
            cout << setw(10) << fixed << setprecision(2) << weeklyAverages[i][week];
        }
        cout << endl;
    }

    cout << "\nCritical Pollution Days for Each City (AQI > 150):" << endl;
    for (int i = 0; i < CITIES; i++)
    {
        cout << cities[i] << ": ";
        bool hasCriticalDays = false;
        for (int j = 0; j < TOTAL_DAYS; j++)
        {
            if (criticalDays[i][j])
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

    cout << "\nHighest and Lowest AQI Values for Each City:" << endl;
    cout << setw(15) << left << "City" << setw(15) << "Highest AQI" << setw(15) << "Lowest AQI" << endl;
    for (int i = 0; i < CITIES; i++)
    {
        cout << setw(15) << left << cities[i] << setw(15) << highestAQI[i] << setw(15) << lowestAQI[i] << endl;
    }

    return 0;
}