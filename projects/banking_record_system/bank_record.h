#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Account{

private:
    // User specified data
    string name;
    int account_number;
    double balance;

    // Data for the bank
    // static std::map<int, Account> users;
    static int user_count;

public:

    // constructor
    Account(string name);

    // user specific functions
    void display_user() const;
    double get_balance() const;
    string get_name() const;
    int get_account_number() const;
    void deposit(double);
    void withdraw(double);

    // static functions
    static Account search(int acc);
    static vector<Account> search(string name);
    static void display_All();
    static void delete_user(int);
};

int Account :: user_count = 0;

Account :: Account(string name){

    user_count++;

    this->name = name;
    account_number = user_count;
    balance = 0;

    // users[account_number] = *this;
}

void Account :: display_user() const{
    
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}

void Account :: deposit(double amount){

    balance += amount;
}

void Account :: withdraw(double amount){

    if (amount > balance + 1000)
    {
        cout << "Insufficient funds" << endl;
    }
    else balance -= amount;
}

int Account :: get_account_number() const
{
    return account_number;
}

string Account :: get_name() const
{
    return name;
}

double Account :: get_balance() const
{
    return balance;
}

vector<Account> Account :: search(string name)
{
    ifstream fin;
    fin.open("Bank_record.csv");
}