#include <bits/stdc++.h>
using namespace std;

// returns true if n is power of 8
bool checkPowerof8(unsigned n)
{
	/*	for(int i = 1; i < INT_MAX; i = i*8)
		cout << bitset<32>(i) << endl;
	*/		
	// return true if n is power of 2 and its only
	// set bit is present at (0, 3, 6, ... ) position
	return n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
}

int main() 
{
	unsigned n = 512;

	if (checkPowerof8(n))
		cout << n << " is power of 8";
	else 
		cout << n << " is not a power of 8";

	return 0;
}