#include <iostream>
#include <cmath>
using namespace std;

// compute power of two less than or equal to n
unsigned previousPowerOf2(unsigned n)
{
	// initialize result by 1
	int k = 1;

	// double k and divide n in half till it becomes 0
	while (n >>= 1)
		k = k << 1; // double k

	return k;
}

int main()
{
	unsigned n = 127;

	cout << "Previous power of 2 is " << previousPowerOf2(n);

	return 0;
}
