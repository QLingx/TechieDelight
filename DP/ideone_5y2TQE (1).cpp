#include <bits/stdc++.h>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;
	
// Function to find length of Longest Common Subsequence of
// array X[0..m-1] and Y[0..n-1]
int LCSLength(int X[], int Y[], int m, int n)
{
	// return if we have reached the end of either array
	if (m == 0 || n == 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(m) + "|" + to_string(n);

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// if last element of X and Y matches
		if (X[m - 1] == Y[n - 1])
			lookup[key] = LCSLength(X, Y, m - 1, n - 1) + 1;
		
		else
		// else if last element of X and Y don't match
		lookup[key] = max(LCSLength(X, Y, m, n - 1), 
						  LCSLength(X, Y, m - 1, n));
	}
	
	// return the subproblem solution from the map
	return lookup[key];
}

// Function to remove duplicates from a sorted array
int removeDuplicates(int X[], int n)
{
	int k = 0;
	for (int i = 1; i < n; i++)
		if (X[i] != X[k])
			X[++k] = X[i];

	// return length of sub-array containing all distinct charcaters
	return k + 1;
}

// Iterative function to find length of longest increasing subsequence (LIS)
// of given array using longest common subsequence (LCS)
int findLIS(int X[], int n)
{
	// create a copy of the original array
	int Y[n];
	for (int i = 0; i < n; i++)
		Y[i] = X[i];
	
	// sort the copy of the original array
	sort(Y, Y + n);

	// remove all the duplicates from Y
	int m = removeDuplicates (Y, n);

	// perform LCS of both
	return LCSLength(X, Y, n, m);
}

// main function
int main()
{
	int X[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(X)/sizeof(X[0]);

	cout << "The length of LIS is " << findLIS(X, n);
	
	return 0;
}