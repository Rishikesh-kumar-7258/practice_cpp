#include <iostream>
using namespace std;

int count_inversion(int arr[], int n); // The Brute force method
int count_inversion2(int arr[], int n, int l, int r,int count=0); // The optimised method

int main()
{
	int arr[] = {2, 3, 8, 6, 1}; // Initializing array
	int n = sizeof(arr)/sizeof(*arr); // storing the size of the array in varable n
	
	cout << count_inversion2(arr, n, 0, n-1) << "\n"; 
	
	for (int i=0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
	
	return 0;
}

int merge(int arr[], int l, int mid, int r,int count)
{
	int n1 = mid - l + 1, n2 = r - mid;
	
	int left[n1], right[n2];
	for (int i = 0; i < n1; i++)
	{
		left[i] = arr[l+i];
	}
	
	for (int i = 0; i < n2; i++) right[i]= arr[mid+i+1];
	
	
	int i = 0, j= 0, k = 0;
	while (i < n1 && j < n2)
	{
		if (right[j] < left[i])
		{
			count += mid - i + 1;
			arr[l+k] = right[j];
			j++;
		}
		else
		{
			arr[l+k] = left[i++];
		}
		
		k++;
	}
	
	while (i < n1) arr[l+k++] = left[i++];
	while (j < n2) arr[l+k++] = right[j++];
	
	return count;
}

// The optimised method
int count_inversion2(int arr[], int n, int l, int r, int count)
{
	if (l == r) return 0;
	
	int mid = (l+r) / 2;
	
	
	count_inversion2(arr, n, l, mid, count);
	cout << "Debugging " << count << "\n";
	count_inversion2(arr, n, mid+1, r, count);
	cout << "Debugging " << count << "\n";
	
	merge(arr, l, mid, r, count);
	cout << "Debugging " << count << "\n";
	
	return count;
	
}

// The brute force method
int count_inversion(int arr[], int n)
{
	int count = 0;
	for (int i=0; i < n-1; i++)
		for (int j=i+1; j < n; j++)
			if (arr[i] > arr[j]) count++;
			
	
	return count;
}
