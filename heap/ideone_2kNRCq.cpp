#include <iostream>
using namespace std;

// Data structure for Max Heap
class MaxHeap
{
	int LEFT(int i);
	int RIGHT(int i); 
	void Heapify(int A[], int i, int n);

public:
	MaxHeap(int A[], int n);
	int pop(int A[], int n);
};

// return left child of A[i]	
int MaxHeap::LEFT(int i) {
	return (2 * i + 1); 
}

// return right child of A[i]   
int MaxHeap::RIGHT(int i) { 
	return (2 * i + 2); 
}

// Function to perform Heapify operation
void MaxHeap::Heapify(int A[], int i, int n)
{
	// get left and right child of node at index i
	int left = LEFT(i);
	int right = RIGHT(i);

	// compare A[i] with its left & right child and store largest value
	int largest = i;

	if (left < n && A[left] > A[i])
		largest = left;

	if (right < n && A[right] > A[largest])
		largest = right;

	// swap with child having greater value & call Heapify on child
	if (largest != i)
	{
		swap(A[i], A[largest]);
		Heapify(A, largest, n);
	}
}

// Constructor (performs Build-Heap operation)
MaxHeap::MaxHeap(int A[], int n)
{
	// call heapify starting from last internal node all the
	// way upto the root node
	int i = (n - 2) / 2;
	while (i >= 0)
		Heapify(A, i--, n);
}
	
// main function
int main()
{
	/* Input: Min Heap
			   1
			   
		  3 		4
		  
		6   10	  8	  5
	
	*/
	// input array (representing the min heap as shown above)
	int A[] = { 1, 3, 4, 6, 10, 8, 5 };
	int n = sizeof(A) / sizeof(A[0]);

	// Initialize max heap by given array
	MaxHeap pq(A, n);

	/* output: Max Heap
			   10
			   
		  6 		8
		  
		1	3	  4	  5 	*/

	cout << "Array representation of Max Heap is : ";
	for (int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}