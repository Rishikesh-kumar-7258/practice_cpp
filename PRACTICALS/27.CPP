#include <iostream.h>
#include <conio.h>

int fact(int);

void main()
{
	clrscr();
	cout << "Enter a number: ";
	int n; cin >> n;
	int ans = fact(n);

	cout << "Factorial of " << n << " is " << ans;
	getch();
}

int fact(int n)
{
	if (n == 0) return 1;
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}