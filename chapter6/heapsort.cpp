#include<iostream>
#include <climits>
using namespace std;

// structure to for our binary tree
struct node
{
    // a node contains and interger value and address of its left and right children
    int data;
    node* left, *right;

    // empty contructor or default constructor
    node()
    {
        data = INT_MIN;
        left = NULL;
        right = NULL;
    }

    // constructor when integer value is passed
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// function to create binary tree from an array
node* make_binary(int arr[], int n, int i);

// function to print the binary tree
void print_tree(node *head);

// function to maintain the max heap
void max_heapify(int arr[],int n, int i);

// function to convert to max_heap
void max_heap(int arr[], int n);

// heapsort function
void heapsort(int arr[], int n);

// Main loop
int main()
{
    int arr[] = {2, 3, 6, 4, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapsort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    
    cout << '\n';

    return 0;
}

void heapsort(int arr[], int n)
{
    max_heap(arr, n);
    int i = n-1;
    while (i > 0)
    {
        swap(arr[i], arr[0]);
        max_heap(arr, i--);
    }
}

void max_heap(int arr[], int n)
{
    int i = n/2;
    while (i > 0) max_heapify(arr, n, i--);
}

void max_heapify(int arr[],int n, int i)
{
    int left = 2*i-1, right = 2*i;

    if (left < n && arr[i-1] < arr[left])
    {
        if (right < n && arr[left] > arr[right])
        {
            swap(arr[i-1], arr[left]);
            max_heapify(arr, n, left+1);
        }
        else 
        {
            swap(arr[i-1], arr[right]);
            max_heapify(arr, n, right+1);
        }
    }
    else if (right < n && arr[i-1] < arr[right])
    {
        swap(arr[i-1], arr[right]);
        max_heapify(arr, n, right+1);
    }
}

void print_tree(node *head)
{
    if (!head) return;

    cout << head->data << " ";
    print_tree(head->left);
    print_tree(head->right);

    return;
}

node* make_binary(int arr[], int n, int i)
{
    /*
    *@arguments
    * arr = array,
    * n   = size of array
    * i   = current position
    */

    if (i > n) return NULL;

    node *head = new node(arr[i-1]);

    head->left = make_binary(arr, n, 2*i);
    head->right = make_binary(arr, n, 2*i+1);

    return head;
}