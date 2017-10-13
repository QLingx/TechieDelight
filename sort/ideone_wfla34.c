#include <stdio.h>
#include <string.h>

/*
  arr -- the input array of integers to be sorted
  n -- the length of the input array
  k -- a number such that all integers are in the range 0..k-1
*/
void countSort(int arr[], int n, int k)
{
	// create an integer array of size k to store count of each integer 
	// in the input array
	int freq[k];

	// initialize the integer array by 0
	memset(freq, 0, sizeof(freq));

	// using value of integer in the input array as index, 
	// store count of each integer in freq[] array
	for (int i = 0; i < n; i++)
		freq[arr[i]]++;

	// overwrite the input array with sorted order
	int index = 0;
	for (int i = 0; i < k; i++)
	{
		while (freq[i]--)
			arr[index++] = i;
	}
}

// C program for counting sort
int main()
{
	int arr[] = { 4, 2, 10, 10, 1, 4, 2, 1, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// range of array elements
	int k = 11;

	countSort(arr, n, k);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}