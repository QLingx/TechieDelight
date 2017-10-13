#include <iostream>
#include <cmath>
using namespace std;

// compute power of two less than or equal to n
unsigned previousPowerOf2(unsigned n)
{
	// drop all set bits from n except its last set bit
	return 1U << (int)log2(n);
}

int main() 
{
	unsigned n = 20;

	cout << "Previous power of 2 is " << previousPowerOf2(n);
	
	return 0;
}
