#include <iostream>
using namespace std;

int findSquare(int num)
{
	// convert number to postive if it is negative
	num = abs(num);
	
	// stores square of the number
	int sq = num;

	// repeatedly add num to the result
	for (int i = 1; i < num; i++)
		sq = sq + num;
	
	return sq;
}

int main()
{
	cout << findSquare(8) << " " << findSquare(-4);
	
	return 0;
}