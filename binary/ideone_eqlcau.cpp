#include <iostream>
#include <math.h>
using namespace std;

// Function to find two repeating elements in an array of size n+2
// having range of elements between [1 to n] using XOR operator
pair<int, int> findDuplicates(int arr[], int n)
{
	// take XOR of all array elements index [0 to n-1] and
	// elements from [1 to n]
	int res = arr[0] ^ arr[n+1];;
	for (int i = 1; i <= n; i++)
        res = res ^ arr[i] ^ i;

	// x and y are two odd appearing elements
	int x = 0, y = 0;

    // res stores (x ^ y)

	// find position of the rightmost set bit in res
	int k = log2(res & -res);

	// split the array into two sub-arrays
	for (int i = 0; i < n + 2; i++)
	{
		// array elements that have k'th bit 1
		if (arr[i] & (1 << k))
			x = x ^ arr[i];

		// array elements that have k'th bit 0
		else
			y = y ^ arr[i];
	}

	// split the range [1-n] into two sub-range
	for (int i = 1; i <= n; i++)
	{
		// number i have k'th bit 1
		if (i & (1 << k))
			x = x ^ i;

		// number i have k'th bit 0
		else
			y = y ^ i;
	}

	return make_pair(x, y);
}

int main()
{
	int arr[] = { 4, 3, 6, 5, 2, 4, 1, 1 };
	int n = 6;	// size of the array is n + 2

	pair<int, int> p = findDuplicates(arr, n);
	cout << "Duplicate elements are " << p.first << " and " << p.second;

	return 0;
}
