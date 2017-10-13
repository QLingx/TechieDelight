#include <iostream>
#include <bitset>
using namespace std;

// compute power of two less than or equal to n
unsigned nextPowerOf2(unsigned n)
{
    cout << bitset<16>(n) << endl;
    
	// Set all bits after the last set bit
	n = n | (n >> 1);
    cout << bitset<16>(n) << endl;
    
    n = n | (n >> 2);
    cout << bitset<16>(n) << endl;
        
    n = n | (n >> 4);
    cout << bitset<16>(n) << endl;
    
    n = n | (n >> 8);
    cout << bitset<16>(n) << endl;
    
    n = n | (n >> 16);
    cout << bitset<8>(n >> 1) << endl;
        
    return n - (n >> 1);
}

int main()
{
	unsigned n = 130;

	cout << "Next power of 2 is " << nextPowerOf2(n);
	
	return 0;
}
