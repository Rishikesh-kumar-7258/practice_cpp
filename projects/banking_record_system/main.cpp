#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include "bank_record.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::getline;

void add_new_record();

int main()
{
    // std::time_t t = std::time(0);
    // std::tm* t2 = std::localtime(&t);
    // cout << (t2->tm_hour) <<  " " << (t2->tm_year) << endl;
    
    bool is_running = true;
    
    while (is_running)
    {
        cout << "Welcome to the banking record system!" << endl;
        cout << "Please choose from below options:" << endl;
        cout << "1. Add a new record" << endl;
        cout << "2. Search for a record" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice here : ";
        int choice; cin >> choice;

        switch(choice)
        {
            case 1:
                add_new_record();
                break;
            case 2 :
                break;
            case 3:
                is_running = false;
                break;
            default:
                break;
        }
    }

    return 0;
}

void add_new_record()
{
    cout << "Enter your name: \n";
    string name;
    getline(cin, name);

    Account new_person(name);

    ofstream fout;
    fout.open("Bank_record.csv", std::ios::app);
    fout << new_person.get_name() << "," << new_person.get_account_number() << "," << new_person.get_balance() << endl;
    fout.close();
    
    cout << "\n\tNew record added successfully!" << endl;
}