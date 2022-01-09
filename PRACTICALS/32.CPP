#include <iostream.h>
#include <conio.h>

struct school
{
	char *name;
	char *city;
};

struct student
{
	char *name;
	int std;
	school sc;
};

void main()
{
	clrscr();
	student a;
	school b;

	cout << "Enter student detials: " << endl;
	cout << "Name: "; cin >> a.name;
	cout << "STD: "; cin >> a.std;
       //	cin.ignore();
	cout << "School name: "; cin >> b.name;
	cout << "School city: "; cin >> b.city;
	cout << endl;
	a.sc = b;

	cout << "\tEntered student details" << endl;
	cout << "Name: " << a.name << endl;
	cout << "STD: " << a.std << endl;
	cout << "School name: " << a.sc.name << endl;
	cout << "School city : " << a.sc.city << endl;


	getch();
}