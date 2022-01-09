#include <iostream.h>
#include <conio.h>
#include <string.h>

void main()
{
	clrscr();
	cout << "Enter the day: ";
	char* s ; cin >> s;

	if (strcmp(s, "sunday") == 0 || strcmp(s, "satruday") == 0)
		cout << "Weekends";
	else cout << "Weekdays";  m
	cout << endl;
	getch();
}