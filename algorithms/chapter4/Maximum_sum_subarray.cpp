#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSubarr(vector<int> , int l, int r); // Divide and conquer method
vector<int> maxFromMid(vector<int>, int l, int mid, int r);

int max_subarray(vector<int>); // Linear non recursive approach

int main()
{
    vector<int> arr = {1, 2, 3, -5,6, 7, -3};
    vector<int> ans = maxSubarr(arr, 0, arr.size()-1);

    cout << "starting from : " << ans[0] << " and ending to " << ans[1] << " is the maximum sum which is equal to " << ans[2] << '\n';
	
//	cout << max_subarray(arr);

    return 0;
}

int max_subarray(vector<int> arr)
{
	int max_sum = 0, curr_sum = 0;
	int i = 0;
	while (i < arr.size())
	{
		max_sum = max(curr_sum, max_sum);
		curr_sum += arr[i];
		
		if (curr_sum < 0)
		{
			curr_sum = 0;
		}
		
		i++;
	}
	
	return max_sum;
	
}

vector<int> maxFromMid(vector<int> arr, int l, int mid, int r)
{
    int i = mid, j= mid, k=mid;
    int left_sum = 0, curr = 0;

    while (k >= 0)
    {
        curr += arr[k];
        if (curr > left_sum)
        {
            left_sum = curr;
            i = k;
        }
        k--;
    }
    
    int right_sum = 0;
    curr = 0;
    k = mid + 1;

    while (k < arr.size())
    {
        curr += arr[k];

        if (curr > right_sum)
        {
            right_sum = curr;
            j = k;
        }
        k++;
    }

    return {i, j, left_sum+right_sum};
}

vector<int> maxSubarr(vector<int> arr, int l, int r)
{
    if (l == r) return {l, r, arr[l]};

    int mid = (l + r) / 2;

    vector<int> left = maxSubarr(arr, l, mid);
    vector<int> right = maxSubarr(arr, mid+1, r);
    vector<int> middle = maxFromMid(arr, l, mid, r);

    if (left[2] > right[2])
    {
        if (left[2] > middle[2]) return left;
        else return middle;
    }
    else
    {
        if (right[2] > middle[2]) return right;
        else return middle;
    }
}