#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int n = 30;
	bitset<8> bs(n);
	cout << "The number of set bits in " << n << " (" << bs << ") is " 
			<< bs.count() << endl;
	
	return 0;
}
