#include<iostream>

using namespace std;

/*
 * Given a limited range of size n where array containes elements between 1 to n-1
 * with one element repeating find the duplicate number in it
 * */

int findDuplicate_v1(int arr[],int n)
{
	bool visited[n];

	fill(visited,visited+n,0);
	for(int i = 0;i < n;i++){
		if(visited[arr[i]]){
			return arr[i];
		}
		visited[arr[i]] = true;
	}

	return -1;
}

int findDuplicate_v2(int arr[],int n)
{
	int duplicate = -1;

	for(int i= 0;i < n;i++){
		int absVal = (arr[i] < 0) ? -arr[i] : arr[i];

		if(arr[absVal-1] >= 0){
			arr[absVal-1] = -arr[absVal-1];
		}else{
			duplicate = absVal;
			break;
		}
	}

	for(int i = 0;i < n;i++){
		if(arr[i] < 0){
			arr[i] = -arr[i];
		}
	}

	return duplicate;
}

int findDuplicate_v3(int arr[],int n)
{
	int XOR = 0;

	for(int i = 0;i < n;i++){
		XOR ^= arr[i];
	}

	for(int i = 1; i < n;i++){
		XOR ^= i;
	}

	return XOR;
}


int main()
{
	int arr[] = {1,2,3,4,4};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<"Dupclicate element is " << findDuplicate_v1(arr,n) <<endl;
	cout<<"Dupclicate element is " << findDuplicate_v2(arr,n) <<endl;
	cout<<"Dupclicate element is " << findDuplicate_v3(arr,n) <<endl;
	return 0;
}
