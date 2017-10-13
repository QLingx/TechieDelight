#include <bits/stdc++.h>
using namespace std;

// macro that defines the size of an integer
// assuming 2 byte storage for integer
#define SIZE 16

// Function to add x and y in binary
int* add(int x, int y)
{
	int carry = 0;
	int n = SIZE;

	// create a array to store binary sum
	int* arr = (int*)malloc(n);

	for (int i = 0; i < n; i++)
	{
		// if x is 1
		if (x & (1 << i)) 
		{
			if (y & (1 << i)) // if both x and y are 1
			{
				if (carry)
					arr[n - i - 1] = 1; // carry = 1
				else
					arr[n - i - 1] = 0, carry = 1;
			}
			else // x is 1, y is 0
			{
				if (carry)
					arr[n - i - 1] = 0; // carry = 1
				else
					arr[n - i - 1] = 1; // carry = 0
			}
		}
		// if x is 0
		else 
		{
			if (y & (1 << i)) // x is 0, y is 1
			{
				if (carry)
					arr[n - i - 1] = 0; // carry = 1
				else
					arr[n - i - 1] = 1; // carry = 0
			}
			else // both x and y are 0
			{
				if (carry == 1)
					arr[n - i - 1] = 1, carry = 0;
				else
					arr[n - i - 1] = 0; // carry = 0
			}
		}
	}

	return arr;
}

int main()
{
	int x = 12731, y = 38023;

	cout << "x (" << x << ") in binary is " << bitset<16>(x) << endl;
	cout << "y (" << y << ") in binary is " << bitset<16>(y) << endl;
	
	int* arr = add(x, y);

	cout << "\nx + y is ";
	for (unsigned i = 0; i < SIZE; i++)
		printf("%d", arr[i]);

	return 0;
}