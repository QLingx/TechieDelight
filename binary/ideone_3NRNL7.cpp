#include <iostream>
#include <bitset>
using namespace std;

// find parity of number n
unsigned findParity(unsigned n)
{
	bool parity = false;
	
	// run till n is not zero
	while (n)
	{
		// invert the parity flag
		parity = !parity;
		
		// turn off rightmost set bit
		n = n & (n - 1);
	}
	
	return parity;
}

int main()
{
	unsigned n = 31;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;

	if (findParity(n))
		cout << "Parity of " << n << " is odd";
	else 
		cout << "Parity of " << n << " is even";

	return 0;
}