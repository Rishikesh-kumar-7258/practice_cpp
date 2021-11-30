#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// find the left child
int Left(int );

// find the right child
int Right(int );

// find the parent
int Parent(int);

// maintains the max-heap property
void max_heapify(int arr[], int pos, int n);

// makes max-heap
void max_heap(int arr[], int);

// heapsort implementation
void heapsort(int arr[], int);

// priority queue
class priorityQueue
{
private:
    vector<int> arr;
public:

    void print_data(); // for showing the data
    // void take_input(); // for taking the data
    void insert(int); // to insert a new element into the heap
    void increase_key(int , int); // to increase a certain index with key
    int maximum(); // return the maximum element
    int extract_max(); // returns and deletes the maximum element
};


int main()
{
    int n; 
    cout << "Enter the number of elements: ";
    cin >> n;

    priorityQueue a;
    a.print_data();

    return 0;
}

int priorityQueue::extract_max()
{
    int max = arr[0];
    int n = arr.size();
    arr[0] = arr[n - 1];
    arr.pop_back();
    n--;

    // max_heapify(arr, 0, n); // we will max-heapify the array to get the result

    return max;
}

int priorityQueue::maximum()
{
    return arr[0];
}

void priorityQueue::increase_key(int key, int index)
{
    if (key < arr[index]) return;

    while (index >= 0 && arr[index] > key)
    {
        swap(arr[index], arr[Parent(index)]);
        index = Parent(index);
    }
}

void priorityQueue::insert(int key)
{
    arr.push_back(INT_MIN);

    int n = arr.size();

    increase_key(key, n-1);
}

// void priorityQueue::take_input()
// {
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++) cin >> arr[i];
// }

void priorityQueue::print_data()
{
    cout << "The elements are: ";
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}

// priorityQueue::priorityQueue(int a)
// {
//     n = a;
//     int arr[n];
// }

void heapsort(int arr[],  int n)
{
    max_heap(arr, n);

    while (n >= 1)
    {

        swap(arr[0], arr[n-1]);

        // cout << "debugging: ";
        // for (int i = 0; i < n; i++) cout << arr[i] << " ";
        // cout << endl;

        max_heapify(arr, 0, n-1);
        n--;

    }
}

void max_heap(int arr[], int n)
{
    int mid = Parent(n-1);

    while (mid >= 0)
    {
        max_heapify(arr, mid, n);
        mid--;
    }
}

void max_heapify(int arr[], int pos, int n)
{
    int left = Left(pos);
    int right = Right(pos);

    if (left >= n) return;

    if (right < n && arr[pos] >= arr[left] && arr[pos] >= arr[right]) return;

    if (arr[pos] > arr[left])
    {
        if (right < n && arr[pos] < arr[right]) 
        {
            swap(arr[pos], arr[right]);
            max_heapify(arr, right, n);
        }
    }
    else if (arr[pos] < arr[left])
    {
        if (right < n && arr[left] > arr[right]) 
        {
            swap(arr[pos], arr[left]);
            max_heapify(arr, left, n);
        }
        else if (right < n)
        {
            swap(arr[pos], arr[right]);
            max_heapify(arr, right, n);
        }
    }

}

int Left(int n)
{
    n++;

    return 2*n-1;
}

int Right(int n)
{
    n++;

    return 2*n;
}

int Parent(int n)
{
    n++;

    return n / 2 - 1;
}