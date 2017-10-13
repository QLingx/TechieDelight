#include <algorithm>
#include <iostream>
#include <vector>

// main function
int main()
{
	std::vector<int> a = { 7, 4, 6, 3, 9, 1 };
	const std::size_t k = 2;

	std::nth_element(a.begin(), a.begin() + a.size() - k, a.end());

	std::cout << "K'th largest element in the array is " << a[a.size() - k];

	return 0;
}