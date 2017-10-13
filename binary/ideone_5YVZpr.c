#include <stdio.h>

// Function to find odd occurring element in a given array
int findOddOccuring(int arr[], int n)
{
	int xor = 0;
	for (int i = 0; i < n; i++)
		xor = xor ^ arr[i];

	return xor;
}

// main function
int main()
{
	int arr[] = { 4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Odd occurring element is %d", findOddOccuring(arr, n));

	return 0;
}