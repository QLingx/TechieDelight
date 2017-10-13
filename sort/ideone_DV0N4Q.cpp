#include <bits/stdc++.h>
using namespace std;

// using Lomuto partition scheme
int Partition(int a[], int start, int end)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[end];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = start;	
	
	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot. 
	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[end]);
	
	// return pIndex (index of pivot element)
	return pIndex;
}

// Iterative Quicksort routine
void IterativeQuickSort(int a[], int start, int end)
{
	// stack of std::pairs for storing subarray start and end index
	stack<pair<int, int>> stk;
	
	// push array start and end index to the stack
	stk.push(make_pair(start, end));

	// run till stack is not empty
	while (!stk.empty()) 
	{
		// pop top pair from the list and get sub-array starting 
		// and ending indexes
		start = stk.top().first, end = stk.top().second;
		stk.pop();

		// rearrange the elements across pivot
		int pivot = Partition(a, start, end);

		// push sub-array indexes containing elements that are 
		// less than current pivot to stack
		if (pivot - 1 > start)
			stk.push(make_pair(start, pivot - 1));

		// push sub-array indexes containing elements that are 
		// more than current pivot to stack
		if (pivot + 1 < end)
			stk.push(make_pair(pivot + 1, end));
	}
}

int main()
{
	int arr[] = { 6, -3, 5, 1, 9, 8, 3, 2, -6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	
	IterativeQuickSort(arr, 0, n - 1);

	// print the sorted array	
	for (int i = 0 ; i < n; i++)
		cout << arr[i] << " ";
}