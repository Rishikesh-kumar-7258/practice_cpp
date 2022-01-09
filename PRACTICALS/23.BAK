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
		temp += rem * rem * rem;
		temp2 /= 10;
	}
	if (temp == n) cout << n << " is a armstrong number" << endl;
	else cout << n << " is not an armstrong number" << endl;
	getch();
}