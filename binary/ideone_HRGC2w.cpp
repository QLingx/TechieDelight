#include <iostream>
using namespace std;

// Naive iterative solution to calculate pow(x, n)
int power(int x, unsigned n)
{
	// initialize result by 1
	int pow = 1;
	
	// multiply x exactly n times
	for(int i = 0; i < n; i++)
		pow = pow*x;

	return pow;
}

int main()
{
	int x = -2;
	unsigned n = 10;

	cout << "pow(" << x << "," << n << ") = " << power(x, n);

	return 0;
}