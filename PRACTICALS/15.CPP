#include <iostream.h>
#include <conio.h>
#include <math.h>

void main()
{
	clrscr();
	cout << "Enter two numbers: ";
	int a, b; cin >> a >> b;
	int ans = (pow(a, 3) - pow(b,3)) / (a - b);

	cout << "The answer of expressmion is: " << ans << endl;

	getch();
}