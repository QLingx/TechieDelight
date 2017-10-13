#include <bits/stdc++.h>
using namespace std;

// M lists
#define M 4

// A heap node
struct Node 
{
	// value stores the element, listNum stores list number of the element
	// index stores column number of the list from which element was taken
	int value, listNum, index;
};

// Comparison object to be used to order the heap
struct comp {
	bool operator()(const Node lhs, const Node rhs) const
	{
		return lhs.value > rhs.value;
	}
};

// Function to compute the minimum range that includes
// at-least one element from given M lists
pair<int, int> findMinimumRange(vector<int> list[])
{
	// high will be maximum element in the heap
	int high = INT_MIN;

	// stores minimum and maximum element found so 
	// far in heap
	pair<int, int> p = { 0, INT_MAX };

	// create an empty min-heap
	priority_queue<Node, std::vector<Node>, comp> pq;

	// push first element of each list into the min-heap
	// along with list number and their index in the list	
	for (int i = 0; i < M; i++) 
	{
		pq.push({list[i][0], i, 0});
		high = max(high, list[i][0]);
	}

	// run till end of any list is not reached	
	for(;;)
	{
		// get root node inforlistion from the min-heap	
		int low = pq.top().value;
		int i = pq.top().listNum;
		int j = pq.top().index;

		// remove root node
		pq.pop();
		
		// update low, high if new min is found
		if (high - low < p.second - p.first)
			p = {low, high};

		// return on reaching the end of any list
		if (j == list[i].size() - 1)
			return p;

		// take next element from "same" list and 
		// insert it into the min-heap
		pq.push({list[i][j + 1], i, j + 1});
		
		// update high if new element is greater
		high = max(high, list[i][j + 1]);
	}
}

int main()
{
	vector<int> list[] = 
	{
		{ 3, 6, 8, 10, 15 },
		{ 1, 5, 12 },
		{ 4, 8, 15, 16},
		{ 2, 6 }
	};

	pair<int, int> p = findMinimumRange(list);
	cout << "Minimum range is " << p.first <<  "-" << p.second << "\n";

	return 0;
}
