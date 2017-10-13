#include <iostream>
#include <bitset>
using namespace std;

int main() 
{
	int n = -6;
	int const mask = n >> sizeof(int) * 8 - 1;

	cout << "n (" << n << ") in binary is " << bitset<8>(n) << endl;
	cout << "mask (" << mask << ") in binary is " << bitset<8>(mask) << endl;
	cout << "n + mask (" << n + mask << ") in binary is " << bitset<8>(n + mask);

	cout << "\n\nabs(" << n << ") is " << ((n + mask) ^ mask);
	
	return 0;
}