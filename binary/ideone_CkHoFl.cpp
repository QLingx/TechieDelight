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
		if(n & 1)
			parity = !parity;
		
		// right shift n by 1 (divide by 2)
		n = n >> 1;
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