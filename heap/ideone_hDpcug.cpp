#include <bits/stdc++.h>
using namespace std;

// Function to find the K'th smallest element in the 
// array using min-heap
int FindKthSmallest(vector<int> &A, int k)
{
	// create an empty min-heap and initialize it with all vector elements
	// use std::greater as the comparison function for min-heap
	priority_queue<int, std::vector<int>, std::greater<int>> pq(A.begin(), A.end());

	// pop from min-heap exactly (k-1) times
	while(--k)
		pq.pop();
	
	// return the root of min-heap	
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
