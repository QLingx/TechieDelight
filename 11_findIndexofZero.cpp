#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findIndexofZero_v1(int arr[],int n)
{
	int max_count = 0;
	int max_index = -1;

	int prev_zero_index = -1;
	int count = 0;

	for(int i = 0;i < n;i++){
		if(arr[i] == 1){
			count++;
		}else{
			count = i - prev_zero_index;
			prev_zero_index = i;
		}

		if(count > max_count){
			max_count = count;
			max_index = prev_zero_index;
		}
	}

	return max_index;
}

int findIndexofZero_v2(int arr[],int n)
{
	for(int i = 0;i < n;i++){
		if(arr[i] == 1){
			arr[i] += arr[i-1];
		}
	}

	int count = 0;

	for(int i = n-1;i >= 0;i--){
		count = max(arr[i],count);

		if(arr[i]){
			arr[i] = count;
		}else{
			count = 0;
		}
	}

	int max_count = 0;
	int max_index = -1;

	for(int i = 0;i < n;i++){
		if(arr[i] == 0){
			if(i == 0 && max_count < arr[i+1]+1){
				max_count = arr[i+1] + 1;
				max_index = i;
			}else if(i == n-1 && max_count < arr[i-1] + 1){
				max_count = arr[i-1] + 1;
				max_index = i;
			}else if(max_count < arr[i-1] + arr[i+1] + 1){
				max_count = arr[i-1] + arr[i+1] + 1;
				max_index = i;
			}
		}
	}

	for(int i = 0;i < n;i++){
		if(arr[i]){
			arr[i] = 1;
		}
	}

	return max_index;
}

int findIndexofZero_v3(int arr[],int n)
{
	int left = 0;
	int count = 0;

	int max_count = 0;
	int max_index = -1;
	int prev_zero_index;

	for(int i = 0;i < n;i++){
		if(arr[i] == 0){
			prev_zero_index = i;
			count++;
		}

		if(count == 2){
			while(arr[left]){
				left++;
			}

			left++;
			count = 1;
		}

		if(i-left+1 > max_count){
			max_count = i-left+1;
			max_index = prev_zero_index;
		}
	}

	return max_index;
}

int main()
{
	int arr[] = {0,0,1,0,1,1,1,0,1,1};
	int n = sizeof(arr) / sizeof(arr[0]);

	int index = findIndexofZero_v2(arr,n);
	index = findIndexofZero_v1(arr,n);
	index = findIndexofZero_v3(arr,n);
	if(index != -1){
		cout << "Index to be replace is " << index <<endl;
	}else{
		cout << "Invalid input" <<endl;
	}
	return 0;
}
