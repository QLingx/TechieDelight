#include <iostream>
#include <unordered_map>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Function to count total number of possible solutions of a
// linear equation of k variables
int count(int coeff[], int k, int rhs)
{
	// if rhs becomes 0, return 1 (solution found)
	if (rhs == 0)
		return 1;

	// return 0 (solution do not exist) if rhs becomes negative or
	// no coefficient is left
	if (rhs < 0 || k < 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(k) + "|" + to_string(rhs);

	// if sub-problem is seen for the first time, solve it and 
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// case 1 
		int include = count(coeff, k, rhs - coeff[k]);

		// case 2
		int exclude = count(coeff, k - 1, rhs);

		// assign total ways by including or excluding current coefficient
		lookup[key] = include + exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
}

// main function
int main()
{
	// k coefficients of given equation
	int coeff[] = { 1, 2, 3 };
	int k = sizeof(coeff) / sizeof(coeff[0]);

	int rhs = 4;

	cout << "Total number of solutions are "
		 << count(coeff, k - 1, rhs);

	return 0;
}