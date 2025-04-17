#include <iostream>
using namespace std;

class FitnessTracker
{
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    float caloriesBurned;

public:
    FitnessTracker(string name, int goal)
    {
        userName = name;
        dailyStepGoal = goal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps)
    {
        if (steps > 0)
        {
            stepsTaken += steps;
            calculateCalories(steps);
            cout << steps << " steps logged successfully!" << endl;
        }
        else
        {
            cout << "Invalid step count.\n";
        }
    }

    void calculateCalories(int steps)
    {
        caloriesBurned += steps * 0.04;
    }

    void showProgress() const
    {
        cout << "\nDaily Progress for " << userName << ":\n";
        cout << "Step Goal: " << dailyStepGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;

        if (stepsTaken >= dailyStepGoal)
        {
            cout << "Congrats! You met your goal today!\n";
        }
        else
        {
            cout << "Keep going! You need "
                 << (dailyStepGoal - stepsTaken) << " more steps to reach your goal.\n";
        }
    }
};

int main()
{
    string name;
    int goal;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your daily step goal: ";
    cin >> goal;

    FitnessTracker laiba(name, goal);

    int choice, steps;

    do
    {
        cout << "\n===== Fitness Tracker Menu =====\n";
        cout << "1. Log Steps\n";
        cout << "2. Show Progress\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of steps: ";
            cin >> steps;
            laiba.logSteps(steps);
            break;

        case 2:
            laiba.showProgress();
            break;

        case 3:
            cout << "Exiting... Stay healthy, " << name << "!\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
