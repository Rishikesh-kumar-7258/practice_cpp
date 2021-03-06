#include <iostream.h>
#include <conio.h>

class matrix
{
	public:
		int row, col;
		int **mat;

		matrix() {row = col = 0;}
		matrix(int a, int b) {row = a; col = b;}

		void display() const;

} ;

matrix operator * (matrix a, matrix &b)
{
	if (a.col != b.row)
	{
		cout << "Cannot be multiplied" << endl;
		return matrix();
	}

	matrix ans(a.row, b.col);

	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < b.col; j++)
		{
			int curr = 0;
			for (int k = 0; k < a.col; k++)
			{
				curr += a.mat[i][k] * b.mat[k][j];
			}
			ans.mat[i][j] = curr;
			curr = 0;
		}
	}

	return ans;
}

void main()
{
	clrscr();
	matrix a(2, 2);
	a.mat = {{1,2}, {3,4}};

	matrix b(2,2);
	b.mat = {{4, 3}, {2,1}};

	matrix c = a*b;
	c.display();
	getch();
}
void matrix :: display() const
		{
			for (int i = 0; i < row;i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << mat[i][j] << " ";
				}
				cout << endl;
			}
		}