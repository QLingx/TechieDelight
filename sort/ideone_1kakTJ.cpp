#include <bits/stdc++.h>
using namespace std;

// Function to find all lexicographically next permutations of a
// string sorted in ascending order using std::prev_permutation
void permutations(string str)
{
	// sort the string in ascending order
	sort(str.begin(), str.end());

	while(1)
	{
		// print current permutation
		cout << str << " ";

		// find next lexicographically ordered permutation
	 	if (!next_permutation(str.begin(), str.end()))
	 		break;
	}
}

// main funtion
int main()
{
	string str = "BADC";
	
	permutations(str);
	
	return 0;
}
