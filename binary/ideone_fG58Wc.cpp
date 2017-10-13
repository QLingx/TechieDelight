#include <iostream>

// negate only when the flag is true
int negate(int n, bool flag)
{
	return (n ^ -flag) + flag;
}

// Conditionally negate a value without branching
int main()
{
	int n = 2;
	
	std::cout << "Don't Negate " << negate(n, 0) << "\n";
	std::cout << "Negate " << negate(n, 1) << "\n";
	
	return 0;
}