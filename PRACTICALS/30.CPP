#include <iostream.h>
#include <conio.h>

void mat_mul(int**, int**, int**);

void main()
{
	clrscr();
	cout << "Enter dimentions of matrix: ";
	int n, m; cin >> n >> m;

	int **a, **b, **ans;
	int i , j , k;
	for (i = 0; i <n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];

	cout << "Enter dimentions of second matrix: ";
	int n2, m2; cin >> n2 >> m2;

	for (i = 0; i < n2; i++)
		for (j=0; j< m2; j++) cin >> b[i][j];

	if (m != n2)
	{
		cout << "Cannot be mulitpied";
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m2; j++)
		{
			int curr = 0;
			for (k = 0; k < m; k++)
			{
				curr += a[i][k] * b[k][j];
			}
			ans[i][j] = curr;
		}
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m2; j++) cout << ans[i][j] << " ";

	getch();
}