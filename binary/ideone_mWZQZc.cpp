#include <iostream>
using namespace std;

// returns true if n is power of four
bool checkPowerof4(unsigned n)
{
	// return true if n is power of 2 and its only
	// set bit is present at even position
	return n && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
}

int main() 
{
	unsigned n = 256;

	if (checkPowerof4(n))
		cout << n << " is power of 4";
	else 
		cout << n << " is not a power of 4";

	return 0;
}