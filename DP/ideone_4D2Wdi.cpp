#include <iostream>
#include <string>
using namespace std;

// Function that matches input string with given wildcard pattern
int isMatching(string str, string pattern)
{
	// get length of string and wildcard pattern 
	int n = str.length();
	int m = pattern.length();

	// create a DP lookup table
	int T[n+1][m+1];
	
	// initialize all elements by 0 (false)
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			T[i][j] = 0;

	// if both pattern and string is empty : match
	T[0][0] = 1;

	// handle empty string case (i == 0)
	for (int j = 1; j <= m; j++) 
		if(pattern[j-1] == '*') 
			T[0][j] = T[0][j-1];

	// build matrix in bottom-up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (pattern[j-1] == '*')
				T[i][j] = T[i-1][j] || T[i][j-1];

			else if (pattern[j-1] == '?' || str[i-1] == pattern[j-1])
				T[i][j] = T[i-1][j-1];
		}
	}

	// last cell stores the answer
	return T[n][m];
}

// Wildcard Pattern Matching
int main()
{
	string str = "xyxzzxy";
	string pattern = "x***x?";

	if (isMatching(str, pattern))
		cout << "Match" << endl;
	else
		cout << "No Match" << endl;

	return 0;
}