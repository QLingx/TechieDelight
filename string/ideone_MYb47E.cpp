#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate factorial of a number
int factorial(int n)
{
	return (n <= 2) ? n : n * factorial(n - 1);
}

// Function to find Lexicographic rank of a string
int findLexicographicRank(string str, int n)
{
	// rank starts from 1
	int rank = 1;

	for (int i = 0; i < n; i++) 
	{
		// count all smaller characters than str[i] to the right of i
		int count = 0;
		for (int j = i + 1; j <= n; j++) 
		{
			if (str[i] > str[j])
				count++;
		}
		// add current count to the rank
		rank += count * factorial(n - i);
	}

	return rank;
}

// main function
int main()
{
	string str = "DCBA";
	int n = str.length();

	cout << "Lexicographic Rank of " << str << " is " 
			<< findLexicographicRank(str, n - 1);

	return 0;
}