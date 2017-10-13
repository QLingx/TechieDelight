#include <iostream>
using namespace std;

// return true if binary representation of n is a palindrome
bool isPalindrome(unsigned n)
{
	// rev stores reverse of binary representation of n
	unsigned rev = 0;
	
	// do till all bits of n are processed
	unsigned k = n;
	while (k)
	{
		// add rightmost bit to rev 
		rev = (rev << 1) | (k & 1);
		k = k >> 1;		// drop last bit
	}

	// return true if reverse(n) is same as n
	return n == rev;
}

int main() 
{
	int n = 9;	// 1001

	if (isPalindrome(n))
		cout << n << " is Palindrome";
	else
		cout << n << " is not a Palindrome";


	return 0;
}