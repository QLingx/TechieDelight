#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findBitonicSubarray(int A[],int n)
{
	int I[n+1];
	I[0] = 1;
	for(int i = 1;i <= n;i++){
		I[i] = 1;
		if(A[i-1] < A[i]){
			I[i] = I[i-1] + 1;
		}
	}

	int D[n+1];
	D[n] = 1;
	for(int i = n-1;i >= 0;i--){
		D[i] = 1;
		if(A[i] > A[i+1]){
			D[i] = D[i+1] + 1;
		}
	}

	int lbs_len = 1;
	int beg = 0,end = 0;

	for(int i = 0;i <= n;i++){
		if(lbs_len < I[i] + D[i] - 1){
			lbs_len = I[i] + D[i] - 1;
			beg = i - I[i] + 1;
			end = i + D[i] - 1;
		}
	}

	cout << "The length of longest bitonic subarray is: " << lbs_len <<endl;
	cout << "The longest bitonic subarray is [" << beg << "," << end << "]" <<endl;
}

void findBitonicSubarray_v1(int A[],int n) //error
{
	int end_index = 0,max_len = 0;

	int i = 0;

	while(i + 1 < n){
		int len = 1;
		while(i+1 < n && A[i] < A[i+1]){
			i++,len++;
		}
		while(i+1 < n && A[i] > A[i+1]){
			i++,len++;
		}

		if(len > max_len){
			max_len = len;
			end_index = i;
		}
	}
	cout << "The length of longest bitonic subarray is: " << max_len <<endl;
	cout << "The longest bitonic subarray is [" << end_index - max_len + 1 << "," << end_index << "]" <<endl;
}

int main()
{
	int A[] = {3,5,8,4,5,9,10,8,5,3,4};
	int A1[] = {3,5,8,5,4,9,8,7,6,5,4};
	int n = sizeof(A) / sizeof(A[0]);
	int n1 = sizeof(A1) / sizeof(A1[0]);

	findBitonicSubarray(A,n-1);
	findBitonicSubarray(A1,n1-1);

	findBitonicSubarray_v1(A,n-1);
	findBitonicSubarray_v1(A1,n1-1);
	return 0;
}
