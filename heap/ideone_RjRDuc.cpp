#include <bits/stdc++.h>
using namespace std;

// Function to find the K'th smallest element in the 
// array using max-heap
int FindKthSmallest(vector<int> &A, int k)
{
	// create an empty max-heap using std::priority_queue
	priority_queue<int, std::vector<int>> pq;

	// insert first k elements of the array into the heap
	for (int i = 0; i < k; i++)
		pq.push(A[i]);

	// do for remaining array elements
	int n = A.size();
	for (int i = k; i < n; i++)
	{
		// if current element is less than the root of the heap
		if (A[i] < pq.top()) 
		{
			// replace root with the current element
			pq.pop();
			pq.push(A[i]);
		}
	}

	// return the root of max-heap
	return pq.top();
}

int main()
{
	vector<int> A  = { 7, 4, 6, 3, 9, 1 };
	int k = 3;

	cout << "K'th smallest element in the array is " << 
			FindKthSmallest(A, k);

	return 0;
}
