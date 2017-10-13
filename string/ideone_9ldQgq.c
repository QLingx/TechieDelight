#include <stdio.h>

// Function to print a subarray formed by [start, end]
void printSubarray(int arr[], int start, int end)
{
	printf("{");

	for (int i = start; i < end; i++)
		printf("%d, ", arr[i]);

	printf("%d}, ", arr[end]);
}

// Function to print all subarrays of the specified array
void printallSubarrays(int arr[], int n)
{
	// consider all subarrays starting from i
	for (int i = 0; i < n; i++)
	{
		// consider all subarrays ending at j
		for (int j = i; j < n; j++)
			printSubarray(arr, i, j);
	}
}

// Program to print all subarrays of the specified array
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr)/sizeof(arr[0]);

	printallSubarrays(arr, n);

	return 0;
}