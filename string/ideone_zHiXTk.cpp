#include <iostream>
#include <cmath>
using namespace std;

// Function to print all subsequences of the specified string
void findPowerSet(string str)
{
	int n = str.length();

	// N stores total number of subsets
	int N = pow(2, n);

	// generate each subset one by one
	for (int i = 0; i < N; i++)
	{
		cout << "'";

		// check every bit of i
		for (int j = 0; j < n; j++)
		{
			// if j'th bit of i is set, print S[j]
			if (i & (1 << j))
				cout << str[j];
		}
		cout << "', ";
	}
}

// Program to print all subsequences of the specified string
int main()
{
	string str = "apple";
	findPowerSet(str);
}