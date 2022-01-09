#include <iostream.h>
#include <conio.h>

class complex
{
	int r;
	int com;
	public:
		complex() { r=com=0;}
		complex(int a, int b) {r = a; com = b;}

		void display() const
		{
			cout << r << " + i" << com;
		}
		complex operator + (const complex &a)
		{
			complex ans;

			ans.r = r + a.r;
			ans.com = com + a.com;

			return ans;
		}
};

void main()
{
	clrscr();
	complex a(3, 4);
	complex b(5, 6);

	complex ans = a + b;
	ans.display();

	getch();
}