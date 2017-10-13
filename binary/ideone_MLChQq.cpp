#include <iostream>
using namespace std;

int findSquare(int num)
{
	int odd = 1;
	int sq = 0;
	
	// convert number to postive if it is negative
	num = abs(num);

	while (num--)
	{
		sq = sq + odd;
		odd = odd + 2;
	}

	return sq;
}

int main()
{
	cout << findSquare(8) << endl;
	cout << findSquare(-4);
	
	return 0;
}