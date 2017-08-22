#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n)
{
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
}

void merge(int X[],int Y[],int m,int n)
{
	int i = 0;
	while(i < m){
		if(X[i] > Y[0]){
			swap(X[i],Y[0]);
			int first = Y[0];
			
			int k;
			for(k = 1;k < n && Y[k] < first;k++){
				Y[k-1] = Y[k];
			}
			Y[k-1] = first;
		}
		i++;
	}
}


int main()
{
	int X[] = {1,4,7,8,10};
	int Y[] = {2,3,9};

	int m = sizeof(X) / sizeof(X[0]);
	int n = sizeof(Y) / sizeof(Y[0]);

	merge(X,Y,m,n);

	cout << "X: ";
	printArray(X,m);
	cout << "Y: ";
	printArray(Y,n);

	return 0;
}
