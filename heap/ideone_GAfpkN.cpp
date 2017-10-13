#include<bits/stdc++.h>
using namespace std;

// Data structure for Max Heap
class PriorityQueue
{
    // return left child of A[i]    
    int LEFT(int i) 
    { 
        return (2 * i + 1); 
    }
 
    // return right child of A[i]   
    int RIGHT(int i) 
    { 
        return (2 * i + 2); 
    }
 
    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    // violates the heap property
    void Heapify(int A[], int i, int size)
	{
		// get left and right child of node at index i
		int left = LEFT(i);
		int right = RIGHT(i);

		int largest = i;

		// compare A[i] with its left and right child
		// and find largest value
		if (left < size && A[left] > A[i])
			largest = left;

		if (right < size && A[right] > A[largest])
			largest = right;

		// swap with child having greater value and 
		// call heapify-down on the child
		if (largest != i) {
			swap(A[i], A[largest]);
			Heapify(A, largest, size);
		}
	}

public:
	
	// Constructor (Build-Heap)
	PriorityQueue(int A[], int n)
	{
		// call heapify starting from last internal node all the
		// way upto the root node
		int i = (n - 2) / 2;
		while (i >= 0)
			Heapify(A, i--, n);
	}

	// function to remove element with highest priority (present at root)
	int pop(int A[], int size)
	{
		// if heap has no elements
		if (size <= 0) {
			return -1;
		}
		int top = A[0];
		// replace the root of the heap with the last element
        // of the array
		A[0] = A[size-1];
		
		// call heapify-down on root node
		Heapify(A, 0, size - 1);
		
		return top;
	}
};

// Function to perform heapsort on array A of size n
void HeapSort(int A[], int n)
{
	// build a priority queue and initialize it by given array
	PriorityQueue pq(A, n);
	
	// pop repeatedly from the heap till it becomes empty
	while(n > 0)
	{
		A[n - 1] = pq.pop(A, n);
		n--;
	}	
}

int main()
{
	int A[] = { 6, 4, 7, 1, 9, -2 };
	int n = sizeof(A) / sizeof(A[0]);

	// perform heapsort on the array
	HeapSort(A, n);

	// print the sorted array
	for (int i = 0; i < n; ++i)
		printf("%d ", A[i]);

	return 0;
}