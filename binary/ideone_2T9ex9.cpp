#include <iostream>
#include <bitset>
using namespace std;

// macros to generate the lookup table (at compile-time)
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)

// lookup-table to store the number of bits set for each index
// in the table. The macro COUNT_BITS generates the table
unsigned int lookup[256] = { COUNT_BITS };

// Function to count number of set bits in n
int numOfSetBits(int n)
{
	// print lookup table (number of bits set for integer i)
	 for (int i = 0; i < 256; i++)
	 cout << i << " has " << (int)lookup[i] << " bits\n";

	// assuming 32-bit(4 byte) integer, break the integer into 8-bit chunks
	// Note mask used 0xff is 11111111 in binary

	int count = lookup[n & 0xff] +	// consider first 8 bits
		lookup[(n >> 8) & 0xff] + 	// consider next 8 bits
		lookup[(n >> 16) & 0xff] +	// consider next 8 bits
		lookup[(n >> 24) & 0xff];	// consider last 8 bits

	return count;
}

int main()
{
	int n = -1;

	cout << n << " in binary is " << bitset<32>(n) << endl;
	cout << "The number of set bits in " << n << " is " << numOfSetBits(n) << endl;

	return 0;
}
