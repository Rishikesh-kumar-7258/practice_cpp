#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// find the determinant using this equation
int solver(vector<vector<int>>);

// main loop
int main()
{
    // size of the matrix
    int n ;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    // Initialising the matrix
    vector<vector<int>> arr(n, vector<int>(n, 0));

    // Enter the elements of the matrix
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // debugging
    // cout << arr.size() << " " << arr[0].size();

    // solving the matrix using solver
    int ans = solver(arr);

    // Outputting the answer
    cout << "The determinant of given matrix is " << ans << "\n";

    return 0;
}

int solver(vector<vector<int>> arr)
{
    // size of the square matrix
    int n = arr.size();

    // checking if the matrix is a square matrix
    assert(n == arr[0].size());

    // checking if it is not an empty matrix
    assert(n >= 1);
    
    // If the size of matrix is 1 return the only element
    if (n == 1) return arr[0][0];

    // If the size of matrix is 2 return according to the formula
    if (n == 2)
    {
        return (arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1]);
    }

    // Initialised ans and assigned it to 0
    int ans = 0;

    // looping throgh 1 col only
    for (int i = 0; i< n; i++)
    {
        // getting to next iteration if the current element is 0
        if (arr[i][0] == 0) continue;

        // making a temporary variable to store the new matrix
        vector<vector<int>> temp;

        // looping through all the rows and columns to make the new matrix
        for (int r = 0; r < n; r++)
        {
            // if the element is present in the current row move ahead
            if (r == i) continue;

            vector<int> t;
            for (int c = 1; c < n; c++)
            {
                t.push_back(arr[r][c]);
            }

            temp.push_back(t);
        }

        ans += arr[i][0]*solver(temp)*((1&i == 0) ? 1 : -1);
    }

    return ans;
}