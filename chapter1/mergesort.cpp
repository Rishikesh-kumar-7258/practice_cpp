#include <iostream>
using namespace std;

void mergesort(int arr[], int, int);
void merge(int arr[], int l, int m, int r);

int main()
{
	int arr[] = {2, 4, 1, 5, 7, 8};
	int l = 0, r = sizeof(arr)/sizeof(*arr) - 1;
	
	for (int i = 0; i <= r; i++) cout << arr[i] << " ";
	cout << "\n";
	
	mergesort(arr, l, r);
	
	for (int i = 0; i <= r; i++) cout << arr[i] << " ";
	cout << "\n";
	return 0;
}

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	
	int left[n1+1], right[n2+1];
	
	for (int i = 0; i < n1; i++)
	{
		left[i] = arr[l+i];
	}
	for (int i = 0; i < n2; i++)
	{
		right[i] = arr[m+1+i];
	}
	
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	
	int i = 0, j = 0;
	for (int k = 0; k < n1+n2+2; k++)
	{
		if (left[i] > right[j])
		{
			arr[l+k] = right[j];
			j++;
		}
		else if (left[i] < right[j])
		{
			arr[l+k] = left[i];
			i++;
		}
	}
}

void mergesort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		
		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		
		merge(arr, l, mid, r);
	}
}