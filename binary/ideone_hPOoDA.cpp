#include <iostream>
#include <bitset>
using namespace std;

// Function to toggle k'th bit of n
int toggleKthBit(int n, int k)
{
	return n ^ (1 << (k - 1));
}

int main()
{
	int n = 20;
	int k = 3;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Toggling k'th bit of n\n";
	n = toggleKthBit(n, k);
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}