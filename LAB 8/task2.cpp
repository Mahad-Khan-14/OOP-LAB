#include <iostream>
#include <string>
using namespace std;

class Account;

class Manager
{
public:
    void displayAccount(const Account &acc);
    void deposit(Account &acc, double amount);
    void withdraw(Account &acc, double amount);
};

class Account
{
private:
    string accountNumber;
    double balance;

public:
    Account(string accNo, double bal) : accountNumber(accNo), balance(bal) {}

    friend class Manager;

    friend void transferFunds(Account &from, Account &to, double amount);
};

void Manager::displayAccount(const Account &acc)
{
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Balance: $" << acc.balance << endl;
}

void Manager::deposit(Account &acc, double amount)
{
    if (amount > 0)
    {
        acc.balance += amount;
        cout << "Deposited $" << amount << " to Account " << acc.accountNumber << endl;
    }
    else
    {
        cout << "Invalid deposit amount!" << endl;
    }
}

void Manager::withdraw(Account &acc, double amount)
{
    if (amount > 0 && amount <= acc.balance)
    {
        acc.balance -= amount;
        cout << "Withdrew $" << amount << " from Account " << acc.accountNumber << endl;
    }
    else
    {
        cout << "Insufficient balance or invalid amount!" << endl;
    }
}

void transferFunds(Account &from, Account &to, double amount)
{
    if (amount > 0 && from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << endl;
    }
    else
    {
        cout << "Transfer failed: Insufficient funds or invalid amount!" << endl;
    }
}

int main()
{

    Account acc1("ACC123", 1000.0);
    Account acc2("ACC456", 500.0);

    Manager manager;

    cout << "Initial Account States:\n";
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);
    cout << "----------------------\n";

    manager.deposit(acc1, 200.0);
    manager.withdraw(acc2, 100.0);

    cout << "----------------------\n";

    transferFunds(acc1, acc2, 300.0);

    cout << "----------------------\n";

    cout << "Final Account States:\n";
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    return 0;
}
