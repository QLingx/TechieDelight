#include <iostream>
using namespace std;

// Function to print n elements of the array arr
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// perform bubble sort on arr[]
void bubbleSort(int arr[], int n)
{
	// (n - 1) pass
	for (int k = 0; k < n - 1; k++) 
	{
		// last k items are already sorted, so inner loop can 
		// avoid looking at the last k items
		for (int i = 0; i < n - 1 - k; i++)
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
				
		// the algorithm can be stopped if the inner loop didn’t do any swap
	}
}

int main()
{
	int arr[] = { 3, 5, 8, 4, 1, 9, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);
	printArray(arr, n);

	return 0;
}
