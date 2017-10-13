#include <iostream>
#include <bitset>
using namespace std;

// return true if adjacent bits are set in binary representation of n
bool check(int n)
{
	return n & (n << 1);
}

int main()
{
	int n = 67;
 	
 	cout << n << " in binary is " << bitset<8>(n) << endl;
 
	if (check(n))
		cout << "Adjacent pair of set bits found";
	else
		cout << "No adjacent pair of set bits found";

	return 0;
}