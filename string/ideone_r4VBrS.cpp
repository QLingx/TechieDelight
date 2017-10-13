#include <iostream>
#include <list>
using namespace std;

// Iterative function to find permutations of a String in C++ using STL
void permutations(string s)
{
	// create an empty list to store (partial) permutations and
	// initialize it with first character of the string
	list<string> partial;

	string firstChar(1, s[0]);
	partial.push_back(firstChar);

	// do for every character of the specified string
	for (int i = 1; i < s.length(); i++)
	{
		// consider previously constructed partial permutation one by one
		for (int j = partial.size() - 1; j >= 0; j--)
		{
			// remove current partial permutation from the list
			string str = partial.front();
			partial.pop_front();

			// Insert next character of the specified string i.e. s.charAt(i) 
			// in all possible positions of current partial permutation. 
			// Then insert each of these newly constructed string in the list
			for (int k = 0; k <= str.length(); k++)
				partial.push_back(str.substr(0, k) + s[i] + str.substr(k));
		}
	}
	
	// The list now contains all permutations of the given string
	for (string s: partial)
		cout << s << ' ' ;
}

// Iterative program to find permutations of a String in C++
int main()
{
	string str = "ABC";
	permutations(str);

	return 0;
}