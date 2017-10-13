#include <iostream>
#include <bitset>
using namespace std;

// Function to find parity of number x
int findParity(int x)
{
	// recursively divide the (32-bit) integer into two equal 
	// halves and take their XOR until only 1 bit is left
	
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	
	// return the last bit
	return x & 1;
}

int main()
{
	int x = 15;
	
	cout << x << " in binary is " << bitset<8>(x) << endl;
	
	if (findParity(x))
		cout << x << " contains odd bits";
	else 
		cout << x << " contains even bits";

	return 0;
}
