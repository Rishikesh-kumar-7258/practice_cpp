/*
*@file = radixSort.cpp
*@author = Rishikesh Kumar
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;


/*
This method sorts the array one digit at a time
*@params - An array and its size
*@return - void
*/
void RadixSort(int arr[], int n);

// main function
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    RadixSort(arr, n);

    cout << "The array after sorting is : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void RadixSort(int arr[], int n)
{
    int max_digits = 0;

    for (int i = 0; i < n; i++) max_digits = max(max_digits, int(log10(arr[i]) + 1));

    for (int j = 0; j < max_digits; j++)
    {
        int temp[10] = {0};
        for (int i = 0; i < n; i++)
            temp[(arr[i] / int(pow(10, j))) % 10]++;
        
        int pos[10], curr_sum = 0;
        for (int i=0; i < 10; i++)
        {
            pos[i] = curr_sum;
            curr_sum += temp[i];
        }

        int a1[n];
        for (int i = 0; i < n; i++)
        {
            int d = (arr[i] / int(pow(10, j))) % 10;
            a1[pos[d]] = arr[i];
            pos[d]++;
        }

        for (int i = 0; i <n; i++) arr[i] = a1[i];

        cout << "Debugging : ";
        for (int i = 0; i <n; i++) cout << arr[i] << " ";
        cout << endl;

    }
}