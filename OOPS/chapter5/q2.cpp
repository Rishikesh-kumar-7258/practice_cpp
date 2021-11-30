/*
Write a class program to represent a vector. 
Include memeber functions to perform the following task.
(a) To create the vector
(b) To modify the value of a given element
(c) To multiply by a scalar value
(d) To display the vector in the form (10, 20, 30...)

*@file - q2.cpp
*@author - Rishikesh Kumar
*/

#include <iostream>
#include <vector>
using namespace std;

class Vector
{
private:
    int size;
    vector<int> arr;
public:
    Vector(); // constructor method
    Vector(int [], int); // constructor method

    void modify(int n, int k); // method to modify the vector
    void multiply(int n); //  method to multipy with a scalar value

    void display() const; // method to display the data
};

// Main function
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Vector a(arr, n);

    a.display();
    a.multiply(5);
    a.display();
    return 0;
}

Vector :: Vector()
{
    size = 0;
}

Vector :: Vector(int a[], int n)
{
    size = 0;
    for (int i = 0; i< n; i++)
    {
        arr.push_back(a[i]);
        size++;
    }
}

void Vector :: modify(int n, int k)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n) 
        {
            arr[i] = k;
            return;
        }
    }
}

void Vector :: multiply(int n)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= n;
    }
}

void Vector :: display() const
{
    cout << "( ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << ")" << endl;
}