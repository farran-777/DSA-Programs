#include <iostream>
using namespace std;

class CheckingAccount {
public:
    CheckingAccount(double startingBalance) {
        if (startingBalance >= 0) {
            balance = startingBalance;
        } else {
            balance = 0;
            cout << "Starting balance cannot be negative. Set to $0." << endl;
        }
    }

    void depositAmount(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit must be a positive value." << endl;
        }
    }

    void withdrawAmount(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Withdrawal amount must be positive and less than or equal to the current balance." << endl;
        }
    }

    double checkCurrentBalance() const {
        return balance;
    }

private:
    double balance;
};

int main() {
    CheckingAccount myChecking(200.0);

    myChecking.depositAmount(75.0);
    myChecking.withdrawAmount(50.0);
    cout << "Current balance: $" << myChecking.checkCurrentBalance() << endl;

    myChecking.withdrawAmount(300.0); // Attempt to withdraw more than the balance

    return 0;
}
