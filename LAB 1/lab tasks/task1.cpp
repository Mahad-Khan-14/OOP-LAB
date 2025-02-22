/*
The goal of this task is to write a program that collects the names of participants for two events. Each event can have a maximum of 5 participants. The names should be stored in two separate arrays.
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

    cout << "\nParticipants for Event 1:" << endl;
    for (int i = 0; i < count1; i++)
    {
        cout << event1[i] << endl;
    }

    cout << "\nParticipants for Event 2:" << endl;
    for (int i = 0; i < count2; i++)
    {
        cout << event2[i] << endl;
    }
    return 0;
}