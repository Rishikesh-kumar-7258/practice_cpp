#include <iostream.h>
#include <conio.h>

class temperature
{
	private:
		char type;
		double value;
	public:
		temperature(double v, char t) {type = t; value = v;}

		void display_alter();

};

void main()
{
	clrscr();
	temperature a(50, 'C');
	a.display_alter();


	getch();
}
void temperature :: display_alter()
{
	if (type == 'C')
	{
		double ans = ((value*9) / 5) + 32;
		cout << "Temperature in fahrenheit is " << ans << endl;
	}
	else if (type == 'F')
	{
		double ans = ((value - 32) * 5) / 9;
		cout << "Tempreature in fahrenheit is " << ans << endl;
	}
	else
	{
		cout << "Invalid temperatur" << endl;
	}
}