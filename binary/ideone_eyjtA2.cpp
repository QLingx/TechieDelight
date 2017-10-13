#include <bits/stdc++.h>
using namespace std;

// Function to print given set
void printSet(vector<int> const &set)
{
	for (int j : set)
		cout << j << " ";
	cout << endl;
}

// Function to generate power set of given set S
void findPowerSet(vector<int> const &S, vector<int> &set, int n)
{
	// if we have considered all elements
	if (n == 0)
	{
		printSet(set);
		return;
	}

	// consider nth element
	set.push_back(S[n - 1]);
	findPowerSet(S, set, n - 1);

	// or don't consider nth element
	set.pop_back();
	findPowerSet(S, set, n - 1);
}

int main()
{
	vector<int> S = { 1, 2, 3 };
	int n = S.size();

	vector<int> set;

	findPowerSet(S, set, n);

	return 0;
}
