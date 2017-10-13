#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

// Function to check if Quad-tuple exists in an array with given sum
bool quadTuple(int arr[], int n, int sum)
{
    // create an empty map
    // key -> sum of a pair of elements in the array
    // value -> vector storing index of every pair having that sum
	unordered_map<int, vector<Pair>> map;

    // consider each element except last element
	for (int i = 0; i < n - 1; i++)
	{
	    // start from i'th element till last element
		for (int j = i + 1; j < n; j++)
		{
            // calculate remaining sum
			int val = sum - (arr[i] + arr[j]);

		    // if remaining sum is found in the map, we have found a Quad-tuple
			if (map.find(val) != map.end())
			{
				// check every pair having sum equal to remaining sum
				for (auto pair : map.find(val)->second)
				{
					int x = pair.first;
					int y = pair.second;

					// if Quad-tuple don't overlap, print it and return true
					if ((x != i && x != j) && (y != i && y != j))
					{
						cout << "Quad-Tuple Found (" << arr[i] << " " << arr[j] 
							<< " " << arr[x] << " " << arr[y] << ")";
						return true;
					}
				}
			}
			
			// insert current pair into the map
            map[arr[i] + arr[j]].push_back({i, j});
		}
	}

    // return false if Quad-tuple don't exist
	return false;
}

// main function
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 20;

	int n = sizeof(arr) / sizeof(arr[0]);

	if (!quadTuple(arr, n, sum))
		cout << "Quad-Tuple Don't Exist";

	return 0;
}
