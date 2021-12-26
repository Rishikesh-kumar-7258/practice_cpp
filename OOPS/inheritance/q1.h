using std::string;
using std::cin;
using std::cout;
using std::endl;

class Account
{
    static float interest_rate;
    static double penalty;
    static int total_accounts;
    static int minimum;

    protected:
        string name, type;
        int account_number;
        double balance;
    public:
        void get_user();
        void desposit(float);
        double display_balance() const;
        void display_user() const;

};

class Current_acc : public Account
{
    public:
        void import_penalty();
};

class Saving_acc : public Account
{
    public:
        void addInterest();
};

float Account :: interest_rate = 2.5;
double Account :: penalty = 75.5;
int Account :: total_accounts = 0;
int Account :: minimum = 1000;

void Account :: get_user()
{
    cout << "\n\t\tWelcome to state bank of Rishi\n\n";
    cout << "\tPleae follow the instructions to create an account\n";
    cout << "\tEnter your name here: ";
    cin >> name;
    cout << "\tChoose an account type\n";
    cout << "\t1. current account\n";
    cout << "\t2. savings account\n";

    short choice;
    cout << "\tEnter your choice here(1, 0): ";
    cin >> choice;

    balance = 0;
    account_number = ++total_accounts;

    cout << "\n\tYour account has been created successfully" << endl;
}