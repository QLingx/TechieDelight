#include <bits/stdc++.h>
using namespace std;

// Function to check if string X[i..j] is a palindrome or not
bool isPalindrome(string X, int i, int j)
{
	while (i <= j) 
	{
		if (X[i++] != X[j--])
			return false;
	}
	return true;
}

// Recursive function to find the minimum cuts needed in a string 
// such that each partition is a palindrome
int minPalinPartition(string X, int i, int j)
{
	// base case: if starting index i and ending index j are equal
	// or X[i..j] is already a palindrome.
	if (i == j || isPalindrome(X, i, j))
		return 0;

	// stores minimum number cuts needed to partition X[i..j]
	int min = INT_MAX;

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
    
	for (int k = i; k <= j - 1; k++) 
	{
		// recuse to get minimum cuts required in X[i..k] and X[k+1..j] 
		int count = 1 + minPalinPartition(X, i, k) + 
					minPalinPartition(X, k + 1, j);

		if (count < min)
			min = count;
	}

    // return the minimum cuts required
	return min;
}

// main function
int main()
{
	string X = "BABABCBADCD";
	int n = X.length();

	cout << "The minimum cuts required are " << minPalinPartition(X, 0, n - 1);

	return 0;
}