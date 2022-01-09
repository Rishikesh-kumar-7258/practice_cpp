#include <iostream.h>
#include <conio.h>

void main()
{
	clrscr();
	cout << "Enter a and b: ";
	int a, b; cin >> a >> b;
	int ans = 1;
	for (int i = 0; i < b; i++) ans *= a;
	cout << a << " to the power " << b << " is " << ans << endl;
	getch();
}