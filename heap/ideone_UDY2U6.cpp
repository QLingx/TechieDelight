#include <bits/stdc++.h>
using namespace std;

// Function to find the K'th largest element in the 
// array using min-heap
int FindKthLargest(vector<int> &A, int k)
{
	// create an empty min-heap using std::priority_queue
	// use std::greater as the comparison function for min-heap
	priority_queue<int, std::vector<int>, std::greater<int>> pq;

	// insert first k elements of the array into the heap
	for (int i = 0; i < k; i++)
		pq.push(A[i]);

	// do for remaining array elements
	int n = A.size();
	for (int i = k; i < n; i++)
	{
		// if current element is more than the root of the heap
		if (A[i] > pq.top())
		{
			// replace root with the current element
			pq.pop();
			pq.push(A[i]);
		}
	}

	// return the root of min-heap
	return pq.top();
}

int main()
{
	vector<int> A  = { 7, 4, 6, 3, 9, 1 };
	int k = 2;

	cout << "K'th largest element in the array is " << 
			FindKthLargest(A, k);

	return 0;
}
