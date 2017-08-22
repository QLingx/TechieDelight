#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void findPair_v1(int arr[],int n,int num)
{
	for (int i = 0;i < n-1;i++){
		for(int j = i;j < n;j++){
			if(num == arr[i] + arr[j]){
				cout << "Pair Found at index (" << i << "," << j <<")"<<endl;
				return;
			}
		}
	}
}

void findPair_v2(int arr[],int n,int sum)
{
	sort(arr,arr+n);

	int low = 0;
	int high = n-1;

	while(low < high){
		if(arr[low] + arr[high] == sum){
			cout << "Pair Found at index (" << low << "," << high <<")"<<endl;
			return;
		}

		(arr[low] + arr[high] < sum) ? low++ : high--;
	}
}

void findPair_v3(int arr[],int n,int sum)
{
	unordered_map<int,int> map;

	for(int i = 0;i < n;i++){
		if(map.find(sum - arr[i]) != map.end()){
			cout << arr[map[sum-arr[i]]] << "and" << arr[i] <<endl;
			cout << "Pair Found at index (" << map[sum-arr[i]] << "," << i <<")"<<endl;
			return;
		}
		map[arr[i]] = i;
	}

	cout << "pair not found" <<endl;

}

int main()
{
	int arr[] = {8,7,2,5,3,1};
	int sum = 10;

	int n = sizeof(arr)/sizeof(arr[0]);

	findPair_v1(arr,n,sum);
	findPair_v2(arr,n,sum);
	findPair_v3(arr,n,sum);//std answer (0,1) dont know why!

	return 0;
}
