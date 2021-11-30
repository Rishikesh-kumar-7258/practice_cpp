/*
Modify the question 1 to handle 10 customers

*@file - q3.cpp
*@author - Rishikesh Kumar
*/

#include<iostream>
using namespace std;

class Account{
    private:
        string name, type;
        int account_number, balance, pin;
    public:
        Account(string, int); // constructor method

        void deposit(); // method to deposit money
        void withdraw(); // method to withdraw money

        bool authenticate(); // method to authenticate the user
        void display() const; // method to display the details
};

int main()
{
    string s;
    cout << "Enter your name: ";
    getline(cin, s);

    int a;
    cout << "Choose the account type:\n\t1. for savings\n\t2. for current\n";
    cin >> a;
    Account me(s, a);

    
    me.deposit();
    me.withdraw();
    me.display();


    return 0;
}

Account :: Account(string s, int a)
{
    name = s;

    account_number = 1234;
    balance = 0;

    if (a == 1) type = "savings";
    else if (a == 2) type = "current";

    cout << "Enter the security pin for: ";
    cin >> pin;
    cout << "please remember your pin and don't share it with anyone\n\n";


    cout << "The account for " << name << " is successfully created.\nYour account number is " << account_number << " and your current balance is " << balance << "\n";
    cout << "Welcome to the prince bank" << endl;
}

bool Account :: authenticate()

{
    string username;
    int password;

    cout << "Enter the user name: ";
    getline(cin, username);

    cout << "Enter your pin: ";
    cin >> password;

    return ((username == name) && (password == pin));
}
void Account :: deposit()
{
    int n;
    cout << "Enter the balance you want to deposit: ";
    cin >> n;

    balance += n;

    cout << "The balance is successfully deposited\n";
    cout << "Total balance is: " << balance << endl;
}

void Account :: withdraw()
{
    int n; 
    cout << "Enter the amount you want to withdraw: ";
    cin >> n;


    if (n > balance) 
    {
        cout << "Insufficient balance!" << endl;
        return;
    }

    balance -= n;

    cout << "successfully withdrawn\nPlease collect your cash" << endl;

}

void Account :: display() const
{
    cout << "Name: " << name;
    cout << "\nAccount Number: " << account_number;
    cout << "\nAccount type: " << type;
    cout << "\nBalance: " << balance;
    cout << endl;
}