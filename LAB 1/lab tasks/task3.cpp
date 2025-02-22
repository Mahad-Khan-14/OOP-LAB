/*
The goal of this task is to calculate the total donation amount collected from both events. Each participant donates 10,so the total donation is the sum of participants in both events multiplied by 10,
*/

#include <iostream>
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

    int donationPerParticipant;

    do
    {
        cout << "Enter the donation amount per participant: $";
        cin >> donationPerParticipant;
        if (donationPerParticipant <= 0)
        {
            cout << "Invalid amount. Please enter a positive number." << endl;
        }
    } while (donationPerParticipant <= 0);

    int totalDonations = (count1 + count2) * donationPerParticipant;

    cout << "Total donations collected: $" << totalDonations << endl;

    return 0;
}