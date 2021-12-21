#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <ctime>
#include "bank_record.h"
// #include "database.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::ostringstream;

void add_new_record();
void search_record();

int main()
{
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
                search_record();
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

void search_record()
{
    cout << "\n\tPlease choose an option\n";
    cout << "\t1. Search by name" << endl;
    cout << "\t2. Search by Account number" << endl;

    int ch; cin >> ch;

    switch(ch)
    {
        case 1:
            break;
        case 2:
            break;
        default:
            cout << "Please enter a valid choice" << endl;
            break;
    }
}

void add_new_record()
{
    cout << "Type your name: ";
    string name;
    cin.ignore(); // without this getline was not working
    getline(cin, name);

    Account new_person(name);

    ofstream fout;
    fout.open("Bank_record.csv", std::ios::app);
    fout << new_person.get_name() << "," << new_person.get_account_number() << "," << new_person.get_balance() << endl;
    fout.close();
    
    cout << "\n\tNew record added successfully!" << endl;
}