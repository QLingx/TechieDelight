#include <bits/stdc++.h>
using namespace std;

#define MAX 20		// define maximum length of the string

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

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

// Recursive function to find the minimum cuts needed in a string 
// such that each partition is a palindrome
int minPalinPartition(string X, int i, int j)
{
	// base case: if starting index i and ending index j are equal
	// or X[i..j] is already a palindrome.
	if (i == j || isPalindrome[i][j])
		return 0;

	// construct a unique map key from dynamic elements of the input
	// lookup[key] stores minimum number cuts needed to partition X[i..j]
	string key = to_string(i) + "|" + to_string(j);

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// take the minimum over each possible position at which the 
	    // string can be cut
	     
	    /*
	        (X[i]) | (X[i+1..j])
	        (X[i..i+1]) | (X[i+2..j])
	        (X[i..i+2]) | (X[i+3..j])
	        ...
	        ...
	        (X[i..j-1]) | (X[j])
	    */
	    lookup[key] = INT_MAX;
		for (int k = i; k <= j - 1; k++) 
		{
			// recuse to get minimum cuts required in X[i..k] and X[k+1..j] 
			int count = 1 + minPalinPartition(X, i, k) + 
						minPalinPartition(X, k + 1, j);
	
			if (count < lookup[key])
				lookup[key] = count;
		}
	}

    // return the minimum cuts required
	return lookup[key];
}

// main function
int main()
{
	string X = "BABABCBADCD";
	int n = X.length();

	// find all substrings of X that are palindromes
	findAllPalindromes(X, n);

	cout << "The minimum cuts required are " << minPalinPartition(X, 0, n - 1);

	return 0;
}