/*
*@file - countingsort.cpp
*@author - Rishikesh Kumar
*@version - 1.1/22-10-2021
*/

#include <iostream>
#include <climits>
using namespace std;

/*
This is a sorting technique used for sorting a specific type of data
*@params - an array of integers, size of the array and an integer k
*@return - void
*/
void countingSort(int [], int, int);

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n], max_i = INT_MIN;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        max_i = max(max_i, arr[i]);
    }

    countingSort(arr, n, max_i);

    cout << "The array after sorting is : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void countingSort(int arr[], int n, int k)
{
    int temp[k+1] = {0};

    for (int i = 0; i < n; i++) temp[arr[i]]++;

    int j = 0;
    for (int i = 0; i <= k; i++)
        while (temp[i]--) arr[j++] = i;
}