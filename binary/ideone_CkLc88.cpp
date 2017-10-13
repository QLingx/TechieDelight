#include <iostream>
#include <bitset>
using namespace std;

// Function to count number of set bits in n
int numOfSetBits(int n)
{
	// stores the total bits set in n
	int count = 0;

	for (; n; count++)
		n = n & (n - 1); // clear the least significant bit set
	
	return count;
}

int main()
{
	int n = -1;

	cout << n << " in binary is " << bitset<32>(n) << endl;
	cout << "The number of set bits in " << n << " is " 
			<< numOfSetBits(n) << endl;
	
	return 0;
}
