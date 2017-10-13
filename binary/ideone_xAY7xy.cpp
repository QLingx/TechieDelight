#include <iostream>
using namespace std;

// Optimized recursive solution to calculate pow(x, n) 
// using divide and conquer
int power(int x, unsigned n)
{
	// base condition
	if (n == 0)
		return 1;

	// calculate sub-problem recursively
	int pow = power(x, n / 2);

	if (n & 1) // if y is odd
		return x * pow * pow;

	// else y is even
	return pow * pow;
}

int main()
{
	int x = -2;
	unsigned n = 10;

	cout << "pow(" << x << "," << n << ") = " << power(x, n);

	return 0;
}
