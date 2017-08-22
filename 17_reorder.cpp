#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int reorder_v1(int A[],int n)
{
	int k = 0;

	for(int i = 0;i < n;i++){
		if(A[i] != 0){
			A[k++] = A[i];
		}
	}

	for(int i = k;i < n;i++){
		A[i] = 0;
	}
}

int reorder_v2(int A[],int n)
{
	int j = 0;

	for(int i = 0;i < n;i++){
		if(A[i] != 0){
			swap(A[i],A[j]);
			j++;
		}
	}
}

int main()
{
	int A[] = {6,0,8,2,3,0,4,0,1};
	int n = sizeof(A) / sizeof(A[0]);

	reorder_v1(A,n);
	reorder_v2(A,n);

	for(int i = 0;i < n;i++){
		cout << A[i] << ",";
	}

	cout << endl;

	return 0;
}
