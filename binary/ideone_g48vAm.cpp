#include <iostream>
#include <bitset>
using namespace std;

// Function to check if k'th bit is set for n or not
int isKthBitset(int n, int k)
{
	return n & (1 << (k - 1));
}

int main()
{
	int n = 20;
	int k = 3;

	cout << n << " in binary is " << bitset<8>(n) << endl;

	if (isKthBitset(n, k))
	    cout << "k-th bit is set";
    else
    	cout << "k-th bit is not set";

	return 0;
}
