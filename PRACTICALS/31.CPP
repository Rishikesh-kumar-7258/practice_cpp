#include <iostream.h>
#include <conio.h>

void swap(int&, int&);

void main()
{
	clrscr();
	cout << "Enter two numbers : ";
	int a, b; cin >> a >> b;

	cout << "before swapping a: " << a << " b: " << b << endl;
	swap(a, b);
	cout << "After swapping a: " << a << " b: " << b << endl;

	getch();
}

void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
	return;
}