#include <iostream.h>
#include <conio.h>
#include <math.h>

void main()
{
	clrscr();
	cout << "Enter the number: ";
	int n; cin >> n;
	int isprime = 1;
	for (int i = 0; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			isprime = 0;
			break;
		}
	}
	if (isprime) cout << "this is a prime number";
	else cout << "This is not a prime number";
	cout << endl;
	getch();
}