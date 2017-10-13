#include <iostream>
#include <bitset>
using namespace std;

// Function to swap b-bits starting from position p and q in an integer n
int swap(int n, int p, int q, int b)
{
	// take XOR of bits to be swapped
	int x = ((n >> p) ^ (n >> q));
	
	// consider only last b-bits of x
	x = x & ((1 << b) - 1);

	// replace the bits to be swapped with the XOR bits
	// and take its XOR with n
	return n ^ ((x << p) | (x << q));
}

int main() 
{
	int n = 15;
	int p = 2, q = 5; // (3rd and 6th bit from the right)
	int b = 2;    // number of consecutive bits in each sequence

	cout << n << " in binary is " << bitset<8>(n) << endl;
	n = swap (n, p, q, b);
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}
