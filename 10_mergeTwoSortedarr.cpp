#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int X[],int Y[],int m,int n)
{
	int k = m + n +1;

	while(m >= 0 && n >= 0){
		if(X[m] > Y[n]){
			X[k--] = X[m--];
		}else{
			X[k--] = Y[n--];
		}
	}
	while(n >= 0){
		X[k--] = Y[n--];
	}
}

void rearrange(int X[],int Y[],int m,int n)
{
	int k = 0;
	for(int i = 0;i < m;i++){
		if(X[i] != 0){
			X[k++] = X[i];
		}
	}

	merge(X,Y,k-1,n-1);
}

int main()
{
	int X[] = {0,2,0,3,0,5,6,0,0};
	int Y[] = {1,8,9,10,15};

	int m = sizeof(X) / sizeof(X[0]);
	int n = sizeof(Y) / sizeof(Y[0]);

	rearrange(X,Y,m,n);

	for(int i = 0; i < m;i++){
		cout << X[i] << " ";
	}
	return 0;
}
