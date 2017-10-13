#include <iostream>
#include <bitset>
using namespace std;

// Function to turn on k'th bit in n
int turnOnKthBit(int n, int k)
{
	return n | (1 << (k - 1));
}

int main()
{
	int n = 20;
	int k = 4;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Turning k'th bit on\n";
	n = turnOnKthBit(n, k);
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	return 0;
}