m#include <iostream.h>
#include <conio.h>
#include <math.h>

double area(double); // Area of circle
double area(double, double); // Area of rectangle
double area(double, double, double); // Area of general triangle

void main()
{
	clrscr();
	cout << "To find area of :\n";
	cout << "1. circle\n";
	cout << "2. rectangle\n";
	cout << "3. triangle\n";
	cout << "Pleae enter the choice: ";
	int ch; cin >> ch;

	switch(ch)
	{
		case 1:
			cout << "Enter the radius of the circle: ";
			int r; cin >> r;
			cout << "Area of the circle is " << area(r);
			break;
		case 2:
			cout << "Enter the length and width of rectangle: ";
			int l, w; cin >> l >> w;
			cout << "Area of the rectangle is " << area(l, w);
			break;
		case 3:
			cout << "Enter the sides of the triangle : ";
			int a, b, c; cin >> a >> b >> c;
			cout << "Area of the triangle is " << area(a, b, c);
			break;
		default:
			cout << "Please enter a valid choice";
			break;

	}

	getch();
}

double area(double r)
{
	return 3.14 * r * r;
}

double area(double l, double w)
{
	return l * w;
}
double area(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	double ans = sqrt(s*(s-a)*(s-b)*(s-c));

	return ans;
}