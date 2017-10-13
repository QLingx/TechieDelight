#include <bits/stdc++.h>
using namespace std;

// Custom comparator function for the vector
bool value_comparer(tuple<int, int, int> const& lhs,
	tuple<int, int, int> const& rhs)
{
	// If two elements have the different frequencies, then 
	// the one which has more frequency should come first
	if (std::get<1>(lhs) != std::get<1>(rhs))
		return std::get<1>(lhs) > std::get<1>(rhs);

	else
	// If two elements have the same frequencies, then the 
	// one which has less index should come first
		return std::get<2>(lhs) < std::get<2>(rhs);
}

// Custom sort by element's frequency and index
void sortByFrequencyAndIndex(int arr[], int n)
{
	if (n < 2)
		return;

	// key -> element, value -> (frequency, first_index)
	map<int, pair<int, int> > hm;

	// for each element of the array, insert into map its frequency 
	// and index of its first occurence in the array
	for (int i = 0; i < n; i++)
	{
		// element seen before
		if (hm.find(arr[i]) != hm.end())
			hm[arr[i]].first++;
		else
			// element is seen for the first time
			hm[arr[i]] = make_pair(1, i);
	}

	// create a vector of tuple
	vector<tuple<int, int, int>> vt;

	// as std::map cannot be sort by their values, create 
	// tuple of all (element, frequency, first_index) pair 
	// and insert it into the vector
	for (auto it : hm) 
	{
		pair<int, int> p = it.second;
		vt.push_back(make_tuple(it.first, p.first, p.second));
	}

	// sort the vector based on custom comparator
	sort(vt.begin(), vt.end(), value_comparer);
	
	int a, b, c, k = 0;
	for (auto tup : vt) 
	{
		tie(a, b, c) = tup;
		for (int j = 0; j < b; j++)
			arr[k++] = a;
	}
}

int main()
{
	int a[] = { 3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	sortByFrequencyAndIndex(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}