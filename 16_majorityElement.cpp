#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int majorityElementNaive(int A[],int n)
{
	for(int i = 0; i < n/2;i++){
		int count = 1;
		for(int j = i + 1;j < n;j++){
			if(A[i] == A[j]){
				count++;
			}
		}
		if(count > n/2){
			return A[i];
		}
	}

	return -1;
}

int majority_v2(int A[],int n)
{
	unordered_map<int,int> map;

	for(int i = 0;i < n;i++){
		map[A[i]]++;
	}

	for(auto pair : map){
		if(pair.second > n/2){
			return pair.first;
		}
	}

	return -1;
}

int majority_v3(int A[],int n)
{
	int m;

	int i = 0;
	for(int j = 0;j < n;j++){
		if(i == 0){
			m = A[j],i = 1;
		}else{
			(m == A[j]) ? i++ : i--;
		}
	}

	return m;
}

int main()
{
	int arr[] = {2,8,7,2,2,5,2,3,1,2,2};
	int n = sizeof(arr) / sizeof(arr[0]);

	int ret = majorityElementNaive(arr,n);
	int ret1 = majority_v2(arr,n);
	int ret2 = majority_v3(arr,n);

	cout << ret << "," << ret1 << "," << ret2 << endl;
	return 0;
}
