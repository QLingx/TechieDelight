#include<iostream>
#include<climits>

using namespace std;

int diff_v1(int arr[],int n)
{
	int diff = INT_MIN;

	for(int i = 0;i < n-1;i++){
		for( int j = i + 1;j < n;j++){
			diff = max(diff,arr[j] - arr[i]);
		}
	}

	return diff;
}

int diff_v2(int arr[],int n)
{
	int diff = INT_MIN;
	int max_so_far = arr[n-1];

	for(int i = n-2;i >= 0;i--){
		if(arr[i] > max_so_far){
			max_so_far = arr[i];
		}else{
			diff = max(diff,max_so_far-arr[i]);
		}
	}

	return diff;
}

int main()
{
	int arr[] = {2,7,9,5,1,3,5};
	int arr1[] = {4,7,9,5,0,8,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	cout << "The maximum difference is " << diff_v1(arr,n) << endl;
	cout << "The maximum difference is " << diff_v1(arr1,n1) << endl;
	cout << "The maximum difference is " << diff_v2(arr,n) << endl;
	cout << "The maximum difference is " << diff_v2(arr1,n1) << endl;
	return 0;
}
