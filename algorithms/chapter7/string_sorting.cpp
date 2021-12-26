#include <bits/stdc++.h>
using namespace std;

bool cmp(char *a, char *b)
{
    return (strcmp(a, b) < 0);
}

int main()
{
    char * arr[] = {(char*)"Prince", (char*)"Bob", (char*)"Vicky"};
    sort(arr, arr+3, cmp);

    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}