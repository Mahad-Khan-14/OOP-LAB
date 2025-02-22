/*
The goal of this task is to create a simple bar chart to visualize the number of participants for each event. Each participant is represented by a * symbol.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int MAX_PARTICIPANTS = 5;
    string event1[MAX_PARTICIPANTS], event2[MAX_PARTICIPANTS];
    int count1 = 0, count2 = 0;

    cout << "Register participants for Event 1 (max 5):" << endl;
    while (count1 < MAX_PARTICIPANTS)
    {
        cout << "Enter name of participant " << count1 + 1 << ": ";
        cin >> event1[count1];
        count1++;
        if (count1 < MAX_PARTICIPANTS)
        {
            cout << "Add another participant? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'n')
                break;
        }
    }

    cout << "\nRegister participants for Event 2 (max 5):" << endl;
    while (count2 < MAX_PARTICIPANTS)
    {
        cout << "Enter name of participant " << count2 + 1 << ": ";
        cin >> event2[count2];
        count2++;
        if (count2 < MAX_PARTICIPANTS)
        {
            cout << "Add another participant? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'n')
                break;
        }
    }

    cout << "\nEvent 1 Popularity: \n";
    for (int i = 0; i < count1; i++)
    {
        cout << "*" << endl;
    }
    cout << endl;

    cout << "Event 2 Popularity: \n";
    for (int i = 0; i < count2; i++)
    {
        cout << "*" << endl;
    }
    cout << endl;

    return 0;
}