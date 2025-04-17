#include <iostream>
#include <string>
using namespace std;

class Wallet
{
private:
    string ownerName;
    float totalBalance;
    string *transactionHistory;
    int transactionCount;
    int capacity;

    void resizeHistory()
    {
        capacity *= 2;
        string *newHistory = new string[capacity];
        for (int i = 0; i < transactionCount; ++i)
        {
            newHistory[i] = transactionHistory[i];
        }
        delete[] transactionHistory;
        transactionHistory = newHistory;
    }

public:
    Wallet(string name, float balance = 0.0)
    {
        ownerName = name;
        totalBalance = balance;
        capacity = 10;
        transactionCount = 0;
        transactionHistory = new string[capacity];
    }

    void addMoney(float amount)
    {
        if (amount > 0)
        {
            totalBalance += amount;
            if (transactionCount >= capacity)
                resizeHistory();
            transactionHistory[transactionCount++] = "Added: Rs. " + to_string(amount);
            cout << "Rs. " << amount << " added successfully!" << endl;
        }
        else
        {
            cout << "Invalid amount. Please enter a positive value.\n";
        }
    }

    void spendMoney(float amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount. Please enter a positive value.\n";
        }
        else if (amount > totalBalance)
        {
            cout << "Insufficient balance! Cannot spend Rs. " << amount << endl;
        }
        else
        {
            totalBalance -= amount;
            if (transactionCount >= capacity)
                resizeHistory();
            transactionHistory[transactionCount++] = "Spent: Rs. " + to_string(amount);
            cout << "Rs. " << amount << " spent successfully." << endl;
            if (totalBalance < 500)
            {
                cout << " Warning: Low balance! Current balance: Rs. " << totalBalance << endl;
            }
        }
    }

    void showTransactionHistory() const
    {
        cout << "\nTransaction History for " << ownerName << ":\n";
        for (int i = 0; i < transactionCount; ++i)
        {
            cout << "- " << transactionHistory[i] << endl;
        }
        cout << " Current Balance: Rs. " << totalBalance << "\n"
             << endl;
    }

    ~Wallet()
    {
        delete[] transactionHistory;
    }
};

int main()
{
    Wallet saadWallet("Saad");

    int choice;
    float amount;

    do
    {
        cout << "\n===== Wallet Menu =====\n";
        cout << "1. Add Money\n";
        cout << "2. Spend Money\n";
        cout << "3. View Transaction History\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to add: Rs. ";
            cin >> amount;
            saadWallet.addMoney(amount);
            break;

        case 2:
            cout << "Enter amount to spend: Rs. ";
            cin >> amount;
            saadWallet.spendMoney(amount);
            break;

        case 3:
            saadWallet.showTransactionHistory();
            break;

        case 4:
            cout << "Exiting. Thank you for using the wallet system!\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
