#include <bits/stdc++.h>
using namespace std;

#define MAX 20 // define maximum length of the string

// isPalindrome[i][j] stores if substring X[i][j] is palindrome or not
bool isPalindrome[MAX][MAX];

// Bottom-up DP function to mark if string X[i..j] is a palindrome
// or not for all possible values of i and j
bool findAllPalindromes(string X, int n)
{
	// initalize lookup table by 0 (can be ignored as lookup is declared global)
	// memset(isPalindrome, 0, sizeof(isPalindrome));

	for (int i = n - 1; i >= 0; i--) 
	{
		for (int j = i; j < n; j++) 
		{
			if (i == j)
				isPalindrome[i][j] = true;
			else if (X[i] == X[j])
				isPalindrome[i][j] = ((j - i == 1) ? true : isPalindrome[i + 1][j - 1]);
			else
				isPalindrome[i][j] = false;
		}
	}
}

// Iterative function to find the minimum cuts needed in a string
// such that each partition is a palindrome
int minPalinPartition(string X, int n)
{
	// create a lookup table to store solutions of subproblems
	// lookup[i] stores the minimum cuts needed in substring X[i..n)
	int lookup[n];

	// start from string's end
	for (int i = n - 1; i >= 0; i--) 
	{
		lookup[i] = INT_MAX;
		
		// if X[i...n-1] is a palindrome, total cuts needed is 0
		if (isPalindrome[i][n-1])
			lookup[i] = 0;
		else 
		{
			// else find lookup[i]
			for (int j = n - 2; j >= i; j--)
				if (isPalindrome[i][j])
					lookup[i] = min (lookup[i], 1 + lookup[j + 1]);
		}
	}
	
	/*for (int i = 0; i < n; i++) 
		cout << lookup[i] << " ";
	cout << endl;*/

	return lookup[0];
}

// main function
int main()
{
	string X = "BABABCBADCEDE";     // BAB|ABCBA|D|C|EDE
	int n = X.length();

	// find all substrings of X that are palindromes
	findAllPalindromes(X, n);

	cout << "The minimum cuts required are " << minPalinPartition(X, n);

	return 0;
}