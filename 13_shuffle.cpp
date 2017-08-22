#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void shuffle_v1(int A[],int n)
{
	for(int i = n-1;i > 0;i--){
		int j = rand() % (i+1);
		swap(A[i],A[j]);
	}
}

int main()
{
	int A[] = {1,2,3,4,5,6};
	int n = sizeof(A) / sizeof(A[0]);

	srand(time(NULL));

	shuffle_v1(A,n);

	for(int i = 0; i < n;i++){
		cout << setw(2) << A[i];
	}

	cout << endl;
	return 0;
}
