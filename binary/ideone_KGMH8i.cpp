#include <iostream>

// negate only when the flag is false
int negate(int n, bool flag)
{
	return (flag ^ (flag - 1)) * n;
}

// Conditionally negate a value without branching
int main()
{
	int n = 2;
	
	std::cout << "Don't Negate " << negate(n, 1) << "\n";
	std::cout << "Negate " << negate(n, 0) << "\n";
	
	return 0;
}