#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void rearrangearr(int arr[],int n)
{
	for(int i = 1;i < n;i+=2){
		if(arr[i-1] > arr[i]){
			swap(arr[i-1],arr[i]);
		}
		if(i+1 < n && arr[i+1] > arr[i]){
			swap(arr[i],arr[i+1]);
		}
	}
}

int main()
{
	int arr[] = {9,6,8,3,7};
	int n = sizeof(arr) / sizeof(arr[0]);

	rearrangearr(arr,n);

	for(int i = 0;i < n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}
