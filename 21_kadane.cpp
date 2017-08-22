#include<iostream>

using namespace std;

int kadane_v1(int arr[],int n)//err {-1,-2,-3,-4,-5,-6}
{
	int max_so_far = 0;
	int max_ending_here = 0;

	for(int i = 0;i < n;i++){
		max_ending_here = max_ending_here + arr[i];
		max_ending_here = max(max_ending_here,0);
		max_so_far = max(max_so_far,max_ending_here);
	}

	return max_so_far;
}

int maximun(int arr[],int n)
{
	int res = arr[0];
	for(int i = 0;i < n;i++){
		res = max(res,arr[i]);
	}
	return res;
}

int kadane_v2(int arr[],int n)
{
	int max_num = maximun(arr,n);

	if(max_num < 0){
		return max_num;
	}

	int max_so_far = 0;
	int max_ending_here = 0;

	for(int i = 0;i < n;i++){
		max_ending_here = max_ending_here + arr[i];
		max_ending_here = max(max_ending_here,0);
		max_so_far = max(max_so_far,max_ending_here);
	}

	return max_so_far;
}

int kadane_v3(int arr[],int n)
{
	int max_so_far = arr[0];
	int max_ending_here = arr[0];

	for(int i = 0;i < n;i++){
		max_ending_here = max_ending_here + arr[i];
		max_ending_here = max(max_ending_here,arr[i]);
		max_so_far = max(max_so_far,max_ending_here);
	}

	return max_so_far;
}

int main()
{
	int arr[] = {-2,1,-1,4,-1,2,1,-5,4};

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The sum of contiguous sub-array with the largest sum is " << kadane_v1(arr,n) << endl;
	cout << "The sum of contiguous sub-array with the largest sum is " << kadane_v2(arr,n) << endl;
	cout << "The sum of contiguous sub-array with the largest sum is " << kadane_v3(arr,n) << endl;
}
