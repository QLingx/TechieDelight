#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void maxLengthSubarr_v1(int arr[],int n,int S)
{
	int len = 0;
	int ending_index = -1;

	for(int i = 0;i < n;i++){
		int sum = 0;
		for(int j = i;j < n;j++){
			sum += arr[j];
			if(sum == S){
				if(len < j-i+1){
					len = j-i+1;
					ending_index = j;
				}
			}
		}
		cout << sum <<endl;
	}

	cout << "[" << ending_index-len+1 << "," <<ending_index<<"]"<<endl;
}

void maxLengthSubarr_v2(int arr[],int n,int S)
{
	unordered_map<int,int> map;
	map[0] = 1;
	int sum = 0;
	int len = 0;

	int ending_index = -1;

	for(int i = 0;i < n;i++){
		sum += arr[i];
		if(map.find(sum) == map.end()){
			map[sum] = i;
		}

		if(sum.find(sum-S) != map.end() && len < i - map[sum-S]){
			len = i- map[sum-S];
			ending_index = i;
		}
	}

	cout << "[" << (ending_index-len+1) << "," <<ending_index << "]" << endl;
}

int main()
{
	int arr[] = {5,6,-5,5,3,5,3,-2,0};
	int sum = 8;

	int n = sizeof(arr) / sizeof(arr[0]);

	maxLengthSubarr(arr,n,sum);

	return 0;
}
