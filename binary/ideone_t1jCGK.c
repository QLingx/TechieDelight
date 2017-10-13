#include <stdio.h>
#include <stdlib.h>

// Recursive function to perform division (x / y) of two positive numbers
// x and y without using division operator in the code
unsigned division(unsigned x, unsigned y)
{
	if (x < y) {
		printf("Remainder is %d\n", x);
		return 0;
	}

	return 1 + division(x - y, y);
}

// Wrapper over division() function to handle negative dividend or divisor
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
	if (x * y < 0)
		sign = -1;

	return sign * division(abs(x), abs(y));
}

// main function to perform division of two numbers
int main(void)
{
	int dividend = 22;
	int divisor = -7;

	printf("Quotient is %d\n", divide(dividend, divisor));

	return 0;
}
