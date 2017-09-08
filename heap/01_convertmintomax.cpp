#include<iostream>
using namespace std;

class MaxHeap{
	int LEFT(int i);
	int RIGHT(int i);
	void Heapify(int A[],int i,int n);

public :
	MaxHeap(int A[],int n);
	int pop(int A[],int n);
};

int MaxHeap::LEFT(int i){
	return (2 * i + 1);
}

int MaxHeap::RIGHT(int i){
	return (2 * i + 2)
}

void MaxHeap::Heapify(int A[],int i,int n){
	int left = LEFT(i);
	int right = RIGHT(i);

	int largest = i;

	if(left < n && A[left] > A[i]){
		largest = left;
	}

	if (right < n && A[right] > A[largest]){
		largest = right
	}

	if (largest != i){
		swap(A[i],A[largest]);
		Heapify(A,largest,n);
	}
}

MaxHeap::MaxHeap(int A[],int n){
	int i = (n-2) / 2;
	while(i >= 0){
		Headpify(A,i--,n);
	}
}


int main(){
	int A[] = {1,3,4,6,10,8,5};
	int n = sizeof(A) / sizeof(A[0]);

	MaxHeap pq(A,n);

	cout << "Array representation of max heapis : ";
	for(int i = 0;i < n;++i){
		cout << A[i] << " ";
	}
	cout <<endl;
}

