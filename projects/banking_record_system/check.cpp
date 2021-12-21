#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <ctime>
#include "database.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::ostringstream;

int main()
{
    // ifstream fin("Bank_record.csv");
    // ostringstream ss;
    // ss << fin.rdbuf();
    // string s = ss.str();

    // cout << s << endl;

    Database db({"Name", "Account", "Balance"});
    db.addrow({"Prince", "20010", "5000"});
    db.showdata();

    // std::time_t t = std::time(0);
    // std::tm* t2 = std::localtime(&t);
    // cout << (t2->tm_hour) <<  " " << (t2->tm_year) << endl;

    return 0;
}
