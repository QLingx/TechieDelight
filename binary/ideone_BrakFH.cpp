#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;
 
// returns position of the only set bit of n
int setBitPos(int n)
{
	// unset rightmost bit and check if the number is non-zero
	if (n & (n - 1))
	{
		cout << "Wrong input";
		return 1;
	}

	return log2(n) + 1;
}
 
int main()
{
	int n = 16;
 
	cout << n << " in binary is " << bitset<8>(n) << endl; 
	cout << "Position of the only set bit is " << setBitPos(n);
 
	return 0;
}