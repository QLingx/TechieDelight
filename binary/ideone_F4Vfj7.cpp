#include <iostream>
#include <cmath>
using namespace std;

// returns true if n is power of 8
bool checkPowerof8(unsigned n)
{
	// find log8(n)
	double i = log(n) / log(8);

	// return true if log8(n) is an integer
	return i - trunc(i) < 0.000001;
}

int main() 
{
	unsigned n = 512*64;

	if (checkPowerof8(n))
		cout << n << " is power of 8";
	else 
		cout << n << " is not a power of 8";

	return 0;
}
