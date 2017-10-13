#include<bits/stdc++.h>
using namespace std;

// Data structure for Min Heap
class MinHeap
{
	// return left child of A[i]	
	int LEFT(int i) {
		return (2 * i + 1); 
	}
 
	// return right child of A[i]   
	int RIGHT(int i) { 
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

		int smallest = i;

		// compare A[i] with its left and right child
		// and find smallest value
		if (left < size && A[left] < A[i])
			smallest = left;

		if (right < size && A[right] < A[smallest])
			smallest = right;

		// swap with child having lesser value and 
		// call heapify-down on the child
		if (smallest != i) {
			swap(A[i], A[smallest]);
			Heapify(A, smallest, size);
		}
	}

public:
	
	// Constructor (Build-Heap)
	MinHeap(int A[], int n)
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

// main function
int main()
{
	/*
			   9
			   
		  4 		7
		  
		1   -2	  6	  5
	
	*/
	// array represeting max heap
	int A[] = { 9, 4, 7, 1, -2, 6, 5 };
	int n = sizeof(A) / sizeof(A[0]);

	// build a min heap by initializing it by given array
	MinHeap pq(A, n);

	// print the Min Heap
	/*
			   -2
			   
		  1 		5
		  
		9	4	  6	  7 	*/
	
	for (int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;

	// pop repeatedly from the heap till it becomes empty
	/* while (n > 0)
	{
		cout << pq.pop(A, n) << " ";
		n--;
	}*/

	return 0;
}