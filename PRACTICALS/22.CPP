#include <iostream.h>
#include <conio.h>

void main()
{
	clrscr();
	cout << "Enter a number: ";
	int n; cin >> n;
	int temp = 0, temp2 = n;
	while (temp2)
	{
		int rem = temp2 % 10;
		temp = temp * 10 + rem;
		temp2 /= 10;
	}
	if (temp == n) cout << n << " is a palindrom";
	else cout << n << " is not a palindrom";
	cout << endl;m
	getch();
}