#include <iostream>
#include <bitset>
using namespace std;
 
// macros to generate the lookup table (at compile-time)
#define P2(n) n, n^1, n^1, n
#define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
#define FIND_PARITY P6(0), P6(1), P6(1), P6(0)
 
// lookup-table to store the parity of each index of the table
// The macro FIND_PARITY generates the table
unsigned int lookup[256] = { FIND_PARITY };
 
// Function to find parity of x
int findParity(int x)
{
	// print lookup table (parity of integer i)
	// for (int i = 0; i < 256; i++)
	//	cout << "Parity of " << i << " is " << lookup[i] << "\n";
 
	// assuming 32-bit(4 byte) integer, break the integer into 
	// 16-bit chunks and take their XOR
	x ^= x >> 16;
	
	// Again split 16-bit chunk into 8-bit chunks and take their XOR
	x ^= x >> 8;
	
	// Note mask used 0xff is 11111111 in binary
	return lookup[x & 0xff];
}

int main()
{
	int x = 17;
	
	cout << x << " in binary is " << bitset<8>(x) << endl;
	
	if (findParity(x))
		cout << x << " contains odd bits";
	else 
		cout << x << " contains even bits";

	return 0;
}