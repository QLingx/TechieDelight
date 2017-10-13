#include <iostream>
using namespace std;

// Iterative function to find permutations of a String
void permutations(string s)
{
	int n = s.length();

	// Weight index control array initialized by 0
	int p[n];
	for (int i = 0; i < n; i++)
	{
		// p[i] == i controls iteration and index boundaries for i
		p[i] = 0;
	}

	// i, j represents upper and lower bound index respectively for swapping
	int i = 1, j = 0;

	// Print given string, as only its permutations will be printed later
	cout << s;

	while (i < n)
	{
		if (p[i] < i)
		{
			// if i is odd then j = p[i], otherwise j = 0
			j = (i % 2) * p[i];

			swap(s[j], s[i]);

			// Print current permutation
			cout << " " << s;

			p[i]++; // increase index "weight" for i by one
			i = 1;  // reset index i to 1
		}
		// otherwise p[i] == i
		else
		{
			// reset p[i] to zero
			p[i] = 0;

			// set new index value for i (increase by one)
			i++;
		}
	}
}

// Iterative program to find permutations of a String in C++
int main()
{
	string str = "ABC";
	permutations(str);

	return 0;
}