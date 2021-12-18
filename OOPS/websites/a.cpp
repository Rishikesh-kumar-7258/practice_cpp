#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> v={{1,2,3,7},{3,4,5,8}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<v[i][j];
        }
        cout << endl;
    }

    vector<int> m = {1,23,4,5,6};

    cout<<m.size();
    cout<<v.size();
    cout<<v[0].size();
    cout << endl;

    return 0;
}