#include <iostream>
using namespace std;

void insertion(int arr[], int);
void insertion_d(int arr[], int n);
void linear_search(int arr[], int n, int v);
void n_bit_sum(int a[], int b[], int c[], int n);
void selection(int arr[], int n);
void insertion_recursive(int arr[], int, int);

int main() {
	int arr[] = {1, 5, 4, 6, 3, 2};
	int n = sizeof(arr)/sizeof(*arr);
	int v = 5;
	int st = 0;
//	cout << n << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	cout << endl;

	insertion_recursive(arr, n, st);

	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	cout << endl;

//	int a[] = {1, 0, 1, 0};
//	int b[] = {0, 1, 1, 0};
//	int n = sizeof(a)/sizeof(*a);
//	int c[n+1];
//
//	n_bit_sum(a, b, c, n);
//
//	for (int i = 0; i <= n; i++) cout << c[i] << " ";
//	cout << endl;

	return 0;
}

void insertion_recursive(int arr[], int n, int st) {
	if (st >= n) return ;

	int j = st, temp = arr[st];
	while (--j >= 0 && arr[j] > temp) arr[j+1] = arr[j];
	
//	for (int i=0; i<n; i++) cout << "DeBuggin" << arr[i] << "\n";

	arr[j+1] = temp;
	
	insertion_recursive(arr, n, ++st);
	
	return ;


}

void selection(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		int min_ind = i;
		for (int j = i; j < n; j++) {
			if (arr[min_ind] > arr[j]) min_ind = j;
		}

		swap(arr[i], arr[min_ind]);
	}
}

void n_bit_sum(int a[], int b[], int c[], int n) {
	int rem = 0;
	for (int i = n-1; i >= 0; i--) {
		int temp = a[i] + b[i] + rem;
		c[i+1] = temp % 2;
		rem = temp / 2;
	}

	c[0] = rem;
}

void linear_search(int arr[], int n, int v) {
	int i=0;
	while (i < n && arr[i] != v) i++;

	if (i == n) cout << "NIL";
	else cout << i;

	cout << '\n';
}

void insertion(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int j = i-1, temp = arr[i];
		while (j >= 0 && temp < arr[j]) {
			arr[j+1] = arr[j];
//			cout << "Debugging" << arr[j] << "\n";
			j--;
		}
		arr[j+1] = temp;

	}

}

void insertion_d(int arr[], int n) {
	for (int i = n-2; i >= 0; i--) {
		int j = i+1, curr = arr[i];
		while (j < n && arr[j] > curr) {
			arr[j-1] = arr[j];
			j++;
		}
		arr[j-1] = curr;
	}
}