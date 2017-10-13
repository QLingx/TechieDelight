#include <bits/stdc++.h>
using namespace std;

// Iterative function to find longest decreasing subsequence
// of given array
void findLDS(int arr[], int n)
{
	// LDS[i] stores the longest decreasing subsequence of sub-array
	// arr[0..i] that ends with arr[i]
	vector<int> LDS[n];

	// LDS[0] denotes longest decreasing subsequence ending with arr[0]
	LDS[0].push_back(arr[0]);

	// start from second element in the array
	for (int i = 1; i < n; i++)
	{
		// do for each element in subarray arr[0..i-1]
		for (int j = 0; j < i; j++)
		{
			// find longest decreasing subsequence that ends with arr[j]
			// where arr[j] is more than the current element arr[i]

			if (arr[j] > arr[i] && LDS[j].size() > LDS[i].size())
				LDS[i] = LDS[j];
		}

		// include arr[i] in LDS[i]
		LDS[i].push_back(arr[i]);
	}

	// uncomment below lines to print contents of vector LDS
	/* for (int i = 0; i < n; i++)
    {
    	cout << "LDS[" << i << "] - ";
    	for (int j : LDS[i])
        	cout << j << " ";
        cout << endl;
    } */

	// j will contain index of LDS
	int j = 0;
	for (int i = 0; i < n; i++)
		if (LDS[j].size() < LDS[i].size())
			j = i;

	// print LDS
	for (int i : LDS[j])
		cout << i << " ";
}

// main function
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findLDS(arr, n);

	return 0;
}
