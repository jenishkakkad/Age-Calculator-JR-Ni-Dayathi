#include <iostream>
#include <stdexcept> // For exception handling
using namespace std;

class ATM
{
private:
    double balance;

public:
    ATM(double initialBalance)
    {
        balance = initialBalance;
    }

    void withdraw(double amount)
    {
        try
        {
            if (amount < 0)
                throw runtime_error("Invalid amount! Withdrawal cannot be negative."); // Handling invalid input

            if (amount > balance)
                throw runtime_error("Insufficient balance! Available: $" + to_string(balance));

            balance -= amount; // Deduct amount only if there is sufficient balance
            cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
        }
        catch (const runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
};

int main()
{
    ATM myATM(500); // Initial balance: $500

    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    myATM.withdraw(amount); // Withdraw money

    return 0;
}
