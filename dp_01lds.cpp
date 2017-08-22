#include<iostream>
#include<climits>

using namespace std;

int LDS_v1(int arr[],int i,int n,int prev)
{
	if(i == n){
		return 0;
	}

	int excl = LDS_v1(arr,i+1,n,prev);

	int incl = 0;
	if(arr[i] < prev){
		incl = 1 + LDS_v1(arr,i+1,n,arr[i]);
	}

	return max(incl,excl);
}

int LDS_v2(int arr[],int n)
{
	int L[n] = {0};

	L[0] = 1;

	for(int i = 1;i < n;i++){
		for(int j = 0;j < i;j++){
			if(arr[j] > arr[i] && L[j] > L[i]){
				L[i] = L[j];
			}
		}
		L[i]++;
	}

	int lis = INT_MIN;
	for(int x : L){
		lis = max(lis,x);
	}

	return lis;
}

int main()
{
	int arr[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LDS is " << LDS_v1(arr,0,n,INT_MAX) << endl;
	cout << "Length of LDS is " << LDS_v2(arr,n) << endl;
	return 0;
}
