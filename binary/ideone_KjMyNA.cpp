#include <iostream>
using namespace std;

// Naive recursive solution to calculate pow(x, n)
// using Divide & Conquer
int power(int x, unsigned n)
{
	// base condition
	if (n == 0)
		return 1;

	if (n & 1) // if n is odd
		return x * power(x, n / 2) * power(x, n / 2);

	// else n is even
	return power(x, n / 2) * power(x, n / 2);
}

int main()
{
	int x = -2;
	unsigned n = 10;

	cout << "pow(" << x << "," << n << ") = " << power(x, n);

	return 0;
}