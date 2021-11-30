#include <iostream>
using namespace std;

// funtion for partition in quicksort
int Partition(int [], int , int);

// Partition function for implementing quicksort in decreasing order
int Part_dec(int [], int, int);

// Quicksort implementation
void Quicksort(int [], int, int);


int main()
{
    int n;
    cout << "Enter the length of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Quicksort(arr, 0, n-1);

    cout << "The elements after sorting are: ";
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}

int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);

    return i+1;
}

int Part_dec(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);

    return i+1;
}

void Quicksort(int arr[], int l, int r)
{
    if (l >= r) return ;

    int pivot = Part_dec(arr, l, r); // for sorting in decreasing order
    // int pivot = Partition(arr, l, r) // for sorting in increasing order

    Quicksort(arr, l, pivot-1);
    Quicksort(arr, pivot + 1, r);
}