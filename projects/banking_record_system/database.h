#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ostringstream;
using std::endl;
using std::cout;
using std::cin;

class Database
{
    private:
        vector<vector<string>> rows;
        vector<string> header;
        string filename;

        vector<string> split_row(string r)
        {
            vector<string> ans;

            string curr = "";
            for (char c : r)
            {
                if (c == ',')
                {
                    ans.emplace_back(curr);
                    curr = "";
                }
                else curr += c;
            }

            ans.emplace_back(curr);

            return ans;
        }

    public:
        Database() {
            filename = "bank_record.csv";
            ofstream fout;
            fout.open(filename);
            fout.close();
        };

        Database(vector<string> header)
        {
            filename = "bank_record.csv";
            ofstream fout(filename);
            this->header = header;
            for (string curr : header)
            {
                fout << curr << ",";
            }
            fout << endl;
            fout.close();
        }

        void addrow(vector<string> row)
        {
            ofstream fout(filename);
            for (string curr : row)
            {
                fout << curr << ",";
            }
            fout << endl;

            fout.close();
        }

        void showdata(){
            
            ifstream fin(filename);
            ostringstream ss;

            ss << fin.rdbuf();
            string s = ss.str();
            
            string line = "";
            for (char c : s)
            {
                line += c;

                if (c == '\n') 
                {
                    vector<string> curr = split_row(line);
                    line = "";

                    for (string col : curr) cout << col << "\t\t";
                    cout << endl;
                }
            }

        }
};