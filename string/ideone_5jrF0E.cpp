#include <iostream>
using namespace std;

// Function to find all occurrences of a pattern of length m
// in given text of length n
void find(string text, string pattern)
{
	int n = text.length();
	int m = pattern.length();

	for (int i = 0; i <= n - m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (text[i + j] != pattern[j])
				break;

			if (j == m - 1)
				cout << "Pattern occurs with shift " << i << endl;
		}
	}
}

// Program to demonstate Naive Pattern Matching Algorithm in C++
int main()
{
	string text = "ABCABAABCABAC";
	string pattern = "CAB";

	find(text, pattern);

	return 0;
}