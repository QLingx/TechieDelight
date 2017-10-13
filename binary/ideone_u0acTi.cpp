#include <iostream>
using namespace std;

int main()
{
	int n = 16;
	cout << "The number of set bits in " << n << " is " 
			<< __builtin_popcount (n) << endl;
	
	return 0;
}
