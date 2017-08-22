#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void maxLengthSubarr(int arr[],int n)
{
	for(int i = 0;i < n;i++){
		arr[i] = arr[i] == 0 ? -1 : 1;
	}

	unordered_map<int,int> map;
	map[0] = -1;
	int len = 0;
	int ending_index = -1;

	int sum = 0;

	for(int i = 0;i < n;i++){
		sum += arr[i];

		if(map.find(sum) != map.end()){
			if(len < i-map[sum]){
				len = i-map[sum];
				ending_index = i;
			}
		}else{
			map[sum] = i;
		}
	}

	for(int i = 0;i < n;i++){
		arr[i] = (arr[i] == -1) ? 0 : 1;
	}

	if(ending_index != -1){
		cout << "[" << ending_index-len+1<<"," << ending_index<<"]"<<endl;
	}else{
		cout << "no sub-array exists"<<endl;
	}
}

int main()
{
	int arr[] = {0,0,1,0,1,0,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	maxLengthSubarr(arr,n);

	return 0;
}
