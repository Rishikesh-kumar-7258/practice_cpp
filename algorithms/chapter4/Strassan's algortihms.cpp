#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_brute(vector<vector<int>> a, vector<vector<int>> b,int n);
vector<vector<int>> matrix_brute_recursive(vector<vector<int>> a, vector<vector<int>> b, int n);

int main()
{
	vector<vector<int>>a = {{1, 2}, {3, 4}}, b = {{2, 1}, {4, 3}};
	int n = a.size();
	
	vector<vector<int>> ans = matrix_brute(a, b, n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

vector<vector<int>> matrix_brute_recursive(vector<vector<int>> a, vector<vector<int>> b, int n)
{
	if (n == 1)
	{
		c[0][0] = a[0][0] * b[0][0];
	}
	if (n <= 2)
	{
		c[0][0] = a[0][0] * b[0][0] + a[0][1] + b[1][0];
		c[0][1] = a[0][0] * b[0][1] + a[0][1] + b[1][1];
		c[1][0] = a[1][0] * b[0][0] + a[1][1] + b[1][0];
		c[1][1] = a[1][0] * b[0][1] + a[1][1] + b[1][1];
	}
	else
	{
		
	}
}

vector<vector<int>> matrix_brute(vector<vector<int>> a, vector<vector<int>> b, int n)
{
	vector<vector<int>> c(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int curr = 0;
			for (int k = 0; k < n; k++)
			{
				curr += a[i][k]*b[k][j];
			}
			
			c[i][j] = curr;
		}
	}
	
	return c;
}