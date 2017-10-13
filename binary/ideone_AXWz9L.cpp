#include <iostream>
#include <cmath>
using namespace std;

// compute power of two greater than or equal to n
unsigned nextPowerOf2(unsigned n)
{
	// decrement n (to handle cases when n itself 
	// is a power of 2)
	n = n - 1;
	
	// initialize result by 2
	int k = 2;

	// double k and divide n in half till it becomes 0
	while (n >>= 1)
		k = k << 1; // double k

	return k;
}

/*
unsigned nextPowerOf2(unsigned n)
{
	int k = 1;
	while (k < n)
		k = k << 1;
	return k;
}
*/

int main()
{
	unsigned n = 127;

	cout << "Next power of 2 is " << nextPowerOf2(n);

	return 0;
}
