#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printAllSubArray_v1(int arr[],int n)
{
	for(int i = 0; i < n;i++){
		int sum = 0;
		for(int j = i;j < n;j++){
			sum += arr[j];

			if(sum == 0){
				cout << "Subarray [" << i << "..." << j << "]" <<endl;
			}
		}
	}
}

void printAllSubArray_v2(int arr[],int n)
{
	unordered_multimap<int,int>map;

	map.insert(pair<int,int>(0,-1));

	int sum = 0;

	for(int i = 0;i < n;i++){
		sum += arr[i];
		if(map.find(sum) != map.end()){
			auto it = map.find(sum);
			while(it != map.end() && it->first == sum){
				cout << "Subarray [" << (it->second + 1) << "..." << i << "]" <<endl;
				it++;
			}
		}

		map.insert(pair<int,int>(sum,i));
	}
}

int main()
{
	int arr[] = {3,4,-7,3,1,3,1,-4,-2,-2};
	int n = sizeof(arr) / sizeof(arr[0]);

	printAllSubArray_v1(arr,n);
	printAllSubArray_v2(arr,n);

	return 0;
}
