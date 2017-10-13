#include <stdio.h>

// Function to perform division (x / y) of two numbers x and y 
// without using division operator in the code
int divide(int x, int y)
{
	// handle divisibility by 0
	if (y == 0)
	{
		printf("Error!! Divisible by 0");
		exit(1);
	}

	// store sign of the result
	int sign = 1;
	if (x * y < 0) {
		sign = -1;
	}

	// convert both dividend and divisor to positive
	x = abs(x);
	y = abs(y);

	unsigned mask = 1;
	unsigned quotient = 0;

	while (y <= x)
	{
		y <<= 1;
		mask <<= 1;
	}

	while (mask > 1)
	{
		y >>= 1;
		mask >>= 1;
		if (x >= y)
		{
			x -= y;
			quotient |= mask;
		}
	}
	
	printf("Remainder is %d\n", x);
	return sign * quotient;
}

// Division of two numbers using low level bits
int main()
{
	int dividend = 22;
	int divisor = -7;

	printf("Quotient is %d\n", divide(dividend, divisor));

	return 0;
}