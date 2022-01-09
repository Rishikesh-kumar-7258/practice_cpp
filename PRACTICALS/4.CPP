#include <iostream.h>
#include <conio.h>

void main()
{
 clrscr();
 float c, f;
 cout << "Enter the temperature in *celcius: ";
 cin >> c;
 f = (c * 9) / 5 + 32;
 cout << "Temperature in fahreinheit is: " << f << endl;
 getch();
}