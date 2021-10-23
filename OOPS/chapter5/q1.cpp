/*
*@file - q1.cpp
*@author - Rishikesh Kumar
*/

#include <iostream>
using namespace std;

class Account{
    private:
        string name, type;
        int account_number, balance;
    public:
        Account(string, int); // constructor method

        void deposit();
        void withdraw();

        void display() const;
};

Account :: Account(string s, int a)
{
    name = s;

    int account_number = 1234;
    int balance = 0;

    if (a == 1) type = "savings";
    else if (a == 2) type = "current";


    cout << "The account for " << name << " is successfully created.\nYour account number is " << account_number << " and your current balance is " << balance;
    cout << "Welcome to the prince bank" << endl;
}

void Account :: deposit()
{
    cout << "Enter the amount you want to desposit";
    int n; cin >> n;

    balance += n;

    cout << "The balance is successfully deposited\n";
    cout << "Total balance is: " << balance << endl;
}

void Account :: withdraw()
{
    bool again = true;

    int n;
    while (again)
    {

        cout << "Enter the amount you want to withdraw";
        cin >> n;

        if (balance >= n) break;
        else
        {
            cout << "Insufficient balance\nEnter q to quit or a to try again: ";
            char c; cin >> c;

            if (c == 'q') return;
        }
    }

    balance -= n;

    cout << "successfully withdrawn\nPlease collect your cash";

}

void Account :: display() const
{
    cout << "Name: " << name;
    cout << "\nAccount Number: " << account_number;
    cout << "\nAccount type: " << type;
    cout << "\nBalance: " << balance;
    cout << endl;
}

int main()
{
    string s;
    cout << "Enter your name: ";
    cin >> s;

    int a;
    cout << "Choose the account type:\n\t1. for savings\n\t2. for current\n";
    cin >> a;

    Account me(s, a);
    me.deposit();
    me.withdraw();
    me.display();

    return 0;
}