#include <iostream>
#include <bitset>
using namespace std;

// Naive solution to count number of set bits in n
int numOfSetBits(int n)
{
	int count = 0;

	for (; n; n >>= 1)
		count += (n & 1);   // check last bit

	return count;
}

int main()
{
	int n = 16;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "The number of set bits in " << n << " is " 
			<< numOfSetBits(n) << endl;
	
	return 0;
}
