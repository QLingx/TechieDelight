#include <iostream>
using namespace std;

int findSquare(int num)
{
	// base case
	if(num < 2)
		return n;

	// convert number to postive if it is negative
	num = abs(num);
	
	// drop last bit from num (divide it by 2)
	int i = num >> 1;
	
	// if num is odd
	if (num & 1)
		return ((findSquare(i) << 2) + (i << 2) + 1);
	// if num is even
	else
		return (findSquare(i) << 2);
}

int main()
{
	cout << findSquare(8);

	return 0;
}
