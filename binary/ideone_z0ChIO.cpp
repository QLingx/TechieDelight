#include <iostream>
using namespace std;

int findMin(int x, int y)
{
	return  y + ((x - y) & ((x - y) >> 31)); 
}

int findMax(int x, int y)
{
	return x - ((x - y) & ((x - y) >> 31));
}

int main()
{
	int x = 2, y = 4;
	
	cout << "min(" << x << ", " << y << ") is " << findMin(x, y);
	cout << "\nmax(" << x << ", " << y << ") is " << findMax(x, y);
	
	return 0;
}