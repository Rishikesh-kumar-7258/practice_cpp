#include <iostream.h>
#include <conio.h>

void main()
{
	clrscr();
	cout << "Enter two numbers: ";
	float a, b; cin >> a >> b;

	cout << "Enter the operator: ";
	char op; cin >> op;
	float ans;

	switch(op)
	{
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/':
			ans = a/b;
			break;
		default:
			cout << "Please enter a valid operator";
			return;
	}

	cout << a << op << b << " is " << ans;
	getch();
}