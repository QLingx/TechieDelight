#include<bits/stdc++.h>

using namespace std;

void sort_v1 (int A[],int n)
{
	int zeros = 0;
	for(int i = 0;i < n;i++){
		if(A[i] == 0){
			zeros++;
		}
	}

	int k = 0;
	while(zeros--){
		A[k++] = 0;
	}

	while(k < n){
		A[k++] = 1;
	}
}

void sort_v2(int A[],int n)
{
	int k = 0;
	for(int i = 0;i < n;i++){
		if(A[i] == 0){
			A[k++] = 0;
		}
	}

	for(int j = k; j < n;j++){
		A[k++] = 1;
	}
}

void sort_v3(int A[],int n)
{
	int pivot = 1;

	int j = 0;

	for(int i = 0;i < n;i++){
		if(A[i] < pivot){
			swap(A[i],A[j]);
			j++;
		}
	}
}

int main()
{
	int A[] = {0,0,1,0,1,0,1,0,0};
	int n = sizeof(A) / sizeof(A[0]);
	sort_v1(A,n);
	sort_v2(A,n);
	sort_v3(A,n);

	for(int i = 0;i < n;i++){
		cout << A[i] << ",";
	}
	return 0;
}
