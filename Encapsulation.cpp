// Data Handling

#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
            cout << "Initial balance cannot be negative. Setting balance to 0." << endl;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        }
        else
        {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew: " << amount << ". New balance: " << balance << endl;
        }
        else
        {
            cout << "Withdrawal amount is invalid or exceeds current balance." << endl;
        }
    }

    double getBalance() const
    { // Controlled Access
        return balance;
    }
};

int main()
{
    BankAccount account(1000);                                   // Initial balance of 1000
    account.deposit(500);                                        // Deposit 500
    account.withdraw(200);                                       // Withdraw 200
    cout << "Current balance: " << account.getBalance() << endl; // Display current balance

    account.withdraw(1500); // Attempt to withdraw more than the balance
    account.deposit(-100);  // Attempt to deposit a negative amount

    return 0;
}