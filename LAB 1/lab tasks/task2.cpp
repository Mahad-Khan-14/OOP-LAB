/*
The goal of this task is to prompt the user to enter a name and check if that name is registered in either of the two events. If the name is found, the program should display which event the participant is registered in. If not, it should inform the user that the participant is not registered in any event.
*/

#include <iostream>
#include <string>
using namespace std;

bool isRegistered(const string participant, const string event[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (event[i] == participant)
        {
            return true;
        }
    }
    return false;
}

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

    string name;
    cout << "Enter the name to check: ";
    cin >> name;

    bool foundInEvent1 = isRegistered(name, event1, count1);
    bool foundInEvent2 = isRegistered(name, event2, count2);

    if (foundInEvent1 && foundInEvent2)
    {
        cout << name << " is registered in both Event 1 and Event 2." << endl;
    }
    else if (foundInEvent1)
    {
        cout << name << " is registered in Event 1." << endl;
    }
    else if (foundInEvent2)
    {
        cout << name << " is registered in Event 2." << endl;
    }
    else
    {
        cout << name << " is not registered in any event." << endl;
    }

    return 0;
}