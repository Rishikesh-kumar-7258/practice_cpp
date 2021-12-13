#include <iostream>

class Account{

private:
    // User specified data
    std::string name;
    int account_number;
    double balance;

    // Data for the bank
    // static std::map<int, Account> users;
    static int user_count;

public:

    // constructor
    Account(std::string name);

    // user specific functions
    void display_user() const;
    void deposit(double);
    void withdraw(double);

    // static functions
    static void search();
    static void display_All();
    static void delete_user(int);
};

int Account :: user_count = 0;

Account :: Account(std::string name){

    user_count++;

    this->name = name;
    account_number = user_count;
    balance = 0;

    // users[account_number] = *this;
}

void Account :: display_user() const{
    
        std::cout << "Account Number: " << account_number << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Balance: " << balance << std::endl;
}

void Account :: deposit(double amount){

    balance += amount;
}

void Account :: withdraw(double amount){

    if (amount > balance + 1000)
    {
        std::cout << "Insufficient funds" << std::endl;
    }
    else balance -= amount;
}