#include <iostream>
using namespace std;

int Partition(int a[], int start, int end)
{
	int pIndex = start;

	// each time we finds a negative number, pIndex is
	// incremented and that element would be placed before
	// the pivot
	for (int i = start; i < end; i++)
	{
		if (a[i] < 0)   // pivot is 0
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
}

int main()
{
	int a[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
	int n = sizeof(a)/sizeof(a[0]);

	Partition(a, 0, n - 1);

	// print the rearranged array
	for (int i = 0 ; i < n; i++)
		cout << a[i] << " ";
}
