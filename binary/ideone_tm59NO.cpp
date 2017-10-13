#include <iostream>
#include <math.h>
using namespace std;

// returns position of the rightmost set bit of n
int rightmostSetBitPos(int n)
{
	// if number is odd, return 1
	if(n & 1)
		return 1;

	return log2(n & -n) + 1;
}

int main()
{
	int n = 20;
	
	cout << "Position of the rightmost set bit is " << rightmostSetBitPos(n);

	return 0;
}