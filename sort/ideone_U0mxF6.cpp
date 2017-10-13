#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countSort(vector<int> &v)
{
	// create an empty map to store frequency of array elements
	map<int, int> freq;

	// store distinct values in the input array as key and 
	// their respective counts as values
	for (int i = 0; i < v.size(); i++)
		freq[v.at(i)]++;

	// traverse the map and overwrite the input array with sorted elements
	// (map will iterate based on the sorted order of keys)
	int i = 0;
	for (auto it : freq)
		while (it.second--)
			v[i++] = it.first;
}

// C++ program for counting sort
int main()
{
	vector<int> v = { 4, 2, 10, 10, 1, 4, 2, 1, 10 };

	countSort(v);

	for (int x : v)
		cout << x << " ";

	return 0;
}