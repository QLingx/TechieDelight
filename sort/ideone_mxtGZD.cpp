#include <iostream>
#include <map>

// Function to efficiently sort an array with many duplicated values
void customSort(int arr[], int n)
{
	// create an empty map to store frequency of array elements
	std::map<int, int> freq;

	// store distinct values in the input array as key and 
	// their respective counts as values
	for (int i = 0; i < n; i++)
		freq[arr[i]]++;

	// sort the map according to the natural ordering of its keys

	// since we have used std::map instead of std::unordered_map, 
	// keys are already sorted by default

	// traverse the sorted map and overwrite the input array with sorted elements
	int i = 0;
	for (auto it : freq)
		while (it.second--)
			arr[i++] = it.first;
}

// Efficiently sort an array with many duplicated values
int main()
{
	int arr[] = { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	customSort(arr, n);

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";

	return 0;
}