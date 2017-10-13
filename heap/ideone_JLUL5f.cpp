#include <bits/stdc++.h>
using namespace std;

// Function to find the K'th largest element in the 
// array using max-heap
int FindKthLargest(vector<int> &A, int k)
{
	// create an empty max-heap using std::priority_queue
	priority_queue<int, std::vector<int>> pq;

	// insert all elements into the heap
	for (int x : A)
		pq.push(x);

	// pop from max-heap exactly (k-1) times
	while(--k)
		pq.pop();

	// return the root of max-heap		
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
