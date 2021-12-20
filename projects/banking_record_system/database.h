#include <iostream>
#include <fstream>
#include <vector>
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

class Database
{
    private:
        vector<vector<string>> rows;
        vector<string> header;
        string filename;

        vector<string> split_row(string row)
        {
            vector<string> ans;

            string curr = "";
            for (char c : row)
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

        void showdata() const{
            
            ifstream fin(filename);
            string line;
            while (getline(fin, line))
            {
                vector<string> d = split_row((string)line);

                for (string i : d) cout << i << "\t\t";
                cout << endl;
            }
            
        }
};