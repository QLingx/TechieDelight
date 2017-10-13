#include <iostream>
#include <bitset>
using namespace std;

// Find number of bits needed to be flipped to convert x to y
int findBits(int x, int y)
{
	// take XOR of x and y and store in n
	int n = x ^ y;
	
	// Using Brian Kernighan's algorithm to count set bits
	
	// count stores the total bits set in n
	int count = 0;

	for (; n; count++)
		n = n & (n - 1); // clear the least significant bit set
	
	return count;

}

int main()
{
	int x = 65;
 	int y = 80;
 	
 	cout << x << " in binary is " << bitset<8>(x) << endl;
 	cout << y << " in binary is " << bitset<8>(y) << endl;

	cout << "\nThe number of bits flipped is " << findBits(x, y);
	
	return 0;
}
