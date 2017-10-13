#include <bits/stdc++.h>
using namespace std;

void customSort(int arr1[], int arr2[], int m, int n)
{
	// map to store frequency of each element of first array 
	unordered_map<int, int> freq;

	// freq frequency of each element of first array and 
	// store it in a map. 
	for(int i = 0; i < m; i++) 
		freq[arr1[i]]++;

	// Note that once we have the frequencies of all elements of 
	// first array, we can overwrite elements of first array
	
	int index = 0;
	// do for every element of second array
	for(int i = 0; i < n; i++) 
	{
		// If current element is present in the map, print it n times 
		// where n is the frequency of that element in first array
		while(freq[arr2[i]]) 
		{
			arr1[index++] = arr2[i];
			freq[arr2[i]]--;
		}
		// erase the element from map
		freq.erase(arr2[i]);
	}

	// Now we are only left with elements that are only present
	// in the first array but not present in the second array
	// We need to sort the remaining elements present in the map
	// Note - If use std::map, keys already sorted
	int i = index;
	for(auto it = freq.begin(); it != freq.end(); ++it)
		while(it->second--)
			arr1[index++] = (it->first);

	// sort the remaining elements
	sort(arr1 + i, arr1 + index);
}

int main()
{
	int arr1[] = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
	int arr2[] = { 3, 5, 7, 2 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	customSort(arr1, arr2, m, n);

	cout << "After sorting the array is : ";
	for(int i = 0; i < m; i++)
		cout << arr1[i] << " ";
	cout << endl;

	return 0;
}
