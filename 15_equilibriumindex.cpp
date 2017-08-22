#include<iostream>
#include<numeric>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

void equilibriumIndex_v1(int A[],int n)
{
	int left[n];

	left[0] = 0;

	for(int i = 1;i < n;i++){
		left[i] = left[i-1] + A[i-1];
	}

	int right = 0;

	for(int i = n-1; i >= 0;i--){
		if(left[i] == right){
			cout << "Equilibrium Index found at: " << i << endl;
		}
		right += A[i];
	}
}

void equilibriumIndex_v2(int A[],int n)
{
	int total = accumulate(A,A+n,0);

	int right = 0;

	for(int i = n-1;i >= 0;i--){
		if(right == total - (A[i] + right)){
			cout << "Equiblibrium Index found at: " << i <<endl;
		}
		right += A[i];
	}
}

int main()
{
	int A[] = {0,-3,5,-4,-2,3,1,0};
	int n = sizeof(A) / sizeof(A[0]);

	equilibriumIndex_v1(A,n);
	equilibriumIndex_v2(A,n);

	return 0;
}
