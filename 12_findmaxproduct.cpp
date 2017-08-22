#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
 * Given an array of integers,find maximum product of two integers in an array
 *
 */

void findMaximumProduct_v1(int arr[],int n)
{
	int max_product = INT_MIN;
	int max_i,max_j;

	for(int i = 0;i < n-1;i++){
		for(int j = i+1;j < n;j++){
			if(max_product < arr[i] * arr[j]){
				max_product = arr[i] * arr[j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout << "(Pair is (" << arr[max_i] << "," << arr[max_j] << ")"<<endl;
}

void findMaximumProduct_v2(int arr[],int n)
{
	sort(arr,arr+n);
	if((arr[0] * arr[1]) > (arr[n-1] * arr[n-2])){	
		cout << "(Pair is (" << arr[0] << "," << arr[1] << ")"<<endl;
	}else{
		cout << "(Pair is (" << arr[n-1] << "," << arr[n-2] << ")"<<endl;
	}
}

void findMaximumProduct_v3(int arr[],int n)
{
	int max1 = arr[0],max2 = INT_MAX;
	int min1 = arr[0],min2 = INT_MAX;
	for(int i = 1;i < n;i++){
		if(arr[i] > max1){
			max2 = max1;
			max1 = arr[i];
		}else if(arr[i] > max2){
			max2 = arr[i];
		}
		if(arr[i] < min1){
			min2 = min1;
			min1 = arr[i]
		}else if(arr[i] < min2){
			min2 = arr[i];
		}
	}

	if(max1 * max2 > min1 * min2){
		cout << "(Pair is (" << max1 << "," << max2 << ")"<<endl;
	}else{
		cout << "(Pair is (" << min1 << "," << min2 << ")"<<endl;
	}

	
}

int main()
{
	int arr[] = {-10,-3,5,6,2};
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaximumProduct_v1(arr,n);
	return 0;
}
