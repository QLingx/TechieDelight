#include <bits/stdc++.h>
using namespace std;

// Partition routine using Dutch National Flag Algorithm
pair<int, int> Partition(int arr[], int start, int end)
{
	int mid = start;
	int pivot = arr[end];

	while (mid <= end)
    {
		if (arr[mid] < pivot)
		{
			swap(arr[start], arr[mid]);
			++start, ++mid;
		}
		else
		if (arr[mid] == pivot)
		{
			++mid;
		}
		else
		if (arr[mid] > pivot)
		{
			swap(arr[mid], arr[end]);
			--end;
		}
	}

	// arr[start .. mid - 1] contains all occurrences of pivot
	return make_pair(start - 1, mid);
}

// Quicksort routine
void QuickSort(int arr[], int start, int end)
{
	// base condition for 0 or 1 elements
	if (start >= end)
		return;

	// handle 2 elements separately as Dutch national flag
	// algorithm will work for 3 or more elements
	if (start - end == 1)
    {
		if (arr[start] < arr[end])
			swap(arr[start], arr[end]);
		return;
	}

    // rearrange the elements across pivot using Dutch 
	// national flag problem algorithm
	pair<int, int> pivot = Partition(arr, start, end);

	// recurse on sub-array containing elements that are less than pivot
	QuickSort(arr, start, pivot.first);

	// recurse on sub-array containing elements that are more than pivot
	QuickSort(arr, pivot.second, end);
}

int main()
{
	int arr[] = { 2, 6, 5, 2, 6, 8, 6, 1, 2, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, n - 1);

	// print the sorted array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}