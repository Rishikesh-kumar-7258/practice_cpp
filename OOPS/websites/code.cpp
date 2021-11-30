#include <iostream>
#include <conio.h>
using namespace std;

inline int sum(int, int);
inline int product(int,int);
int calculate(int (*ptr)(int , int), int, int); // passing function pointer as an agrument

int main()
{
	// int ans = sum(5, product(3, 4)); // we can pass functions as an argument in c++
	// cout << ans << endl;
	
	clscr();
	
	int ans = calculate(sum, 5, 10);
	cout << ans << endl;
	
	return 0;
}

inline int sum(int a,int b)
{
	return a + b;
}

inline int product(int a, int b)
{
	return a*b;
}

int calculate(int (*ptr)(int, int), int a, int b)
{
	return ptr(a, b);
}