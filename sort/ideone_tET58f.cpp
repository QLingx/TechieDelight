#include <iostream>
using namespace std;

// Function to print n elements of the array arr
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// recursive function to perform bubble sort on subarray arr[i..n]
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);
	
	if(n - 1 > 1)
		bubbleSort(arr, n - 1);
}

int main()
{
	int arr[] = { 3, 5, 8, 4, 1, 9, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);
	printArray(arr, n);

	return 0;
}