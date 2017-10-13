#include <stdio.h>

// Iterative function to implement atoi() function in C
long atoi(const char* S)
{
	long num = 0;

	int i = 0;
	
	// run till we have reached end of the string or
	// current character is non-numeric
	while (S[i] && (S[i] >= '0' && S[i] <= '9'))
	{
		num = num * 10 + (S[i] - '0');
		i++;
	}

	return num;
}

// main function
int main(void)
{
	char S[] = "12345";
	
	printf("%ld ", atoi(S));

	return 0;
}