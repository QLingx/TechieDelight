#include <iostream>
using namespace std;

// compute the next highest power of 2 of 32-bit n
unsigned nextPowerOf2(unsigned n)
{
	// decrement n (to handle cases when n itself is a power of 2)
	n--;
	
	// Set all bits after the last set bit
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	
	// increment n and return
	return ++n;
}

int main() 
{
	unsigned n = 131;

	cout << "Next power of 2 is " << nextPowerOf2(n);
	
	return 0;
}