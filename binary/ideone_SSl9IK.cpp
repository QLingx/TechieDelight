#include <iostream>
#include <math.h>
using namespace std;

pair<int, int> findOddOccuring(int arr[], int n)
{
	int res = 0;
	
	// take XOR of all array elements
	for (int i = 0; i < n; i++)
		res = res ^ arr[i];
	
	// find position of the rightmost set bit in res
	int k = log2(res & -res);
	
	// x and y are two odd appearing elements
	int x = 0, y = 0;
	
	// split the array into two sub-arrays
	for (int i = 0; i < n; i++)
	{
		// elements that have k'th bit set
		if (arr[i] & (1 << k))
			x = x ^ arr[i];

		// elements that don't have k'th bit set
		else
			y = y ^ arr[i];
	}

	return make_pair(x, y);
}

int main()
{
	int arr[] = { 4, 3, 6, 2, 4, 2, 3, 4, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	pair<int, int> p = findOddOccuring(arr, n);
	cout << "Odd occurring element are " << p.first << " and " << p.second;

	return 0;
}
