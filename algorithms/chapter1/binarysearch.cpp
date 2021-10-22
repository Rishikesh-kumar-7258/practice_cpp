#include <iostream>
#include <algorithm>
using namespace std;

int binary(int arr[], int l, int h, int key);
int binary_recursive(int arr[], int l, int h, int key);
void two_sum(int arr[], int n, int k);

int main() {
	int arr[] = {1,2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(*arr);

	int key = 14;
	
	two_sum(arr, n, key);

	cout << "\n";

	return 0;
}

void two_sum(int arr[], int n, int k)
{
	sort(arr, arr+n);
	
	int i = 0;
	while (i < n)
	{
		int f = k - arr[i];
		
		int res = binary(arr, i+1, n-1, f);
		
		if (res == -1) i++;
		else 
		{
			cout << i << ' ' << res << '\n';
			return;
		}
	}
	
	cout << "Not found...\n";
	
}

// Iterative apporach
int binary(int arr[], int l, int h, int key) {
	while (l < h) {
		int mid = (l + h) / 2;

		if (arr[mid] > key) h = --mid;
		else if (arr[mid] < key) l = ++mid;
		else return mid;
	}

	return -1;
}

// recursive apporach
int binary_recursive(int arr[], int l, int h, int key) {
	if (l > h) return -1;

	int mid = (l + h) / 2;

	if (arr[mid] > key) h = --mid;
	else if (arr[mid] < key) l = ++mid;
	else return mid;
	
	return binary_recursive(arr, l, h, key);
}