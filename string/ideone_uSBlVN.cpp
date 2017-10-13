#include <iostream>
using namespace std;

// Function to print all non-empty substrings of the specified string
void printallSubstrings(string str)
{
	int n = str.length();

	// consider all substrings starting from i
	for (int i = 0; i < n; i++)
	{
		// consider all substrings ending at j
		for (int j = i; j < n; j++)
		{
			cout << "'" << str.substr(i, j + 1) << "', ";
		}
	}
}

// Program to print all non-empty substrings of the specified string
int main()
{
	string str = "techie";
	printallSubstrings(str);

	return 0;
}