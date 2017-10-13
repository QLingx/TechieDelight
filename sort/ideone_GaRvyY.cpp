#include <iostream>
using namespace std;

// Naive recursive function to check if Quad-tuple exists in an array
// with given sum
bool quadTuple(int arr[], int n, int sum, int count)
{
    // if desired sum is reached with 4 elements, return true
	if (sum == 0 && count == 4)
		return true;

    // return false if sum is not possible with current configuration
	if (count > 4 || n == 0)
		return false;

    // recuse with
    // 1. including current element
    // 2. excluding current element
	return quadTuple(arr, n - 1, sum - arr[n - 1], count + 1) ||
			quadTuple(arr, n - 1, sum, count);
}

// main function
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 20;

	int n = sizeof(arr) / sizeof(arr[0]);

	quadTuple(arr, n, sum, 0) ? cout << "Quad-Tuple Exists":
                                cout << "Quad-Tuple Don't Exist";

	return 0;
}
