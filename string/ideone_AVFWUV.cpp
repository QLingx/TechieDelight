#include <bits/stdc++.h>
using namespace std;

// A Trie node
struct Trie
{
	bool isLeaf;	// set when node is a leaf node
	unordered_map<char, Trie*> character;
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->isLeaf = false;
	
	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie*& head, string str)
{
	// start from root node
	Trie* curr = head;

	for (char ch: str)
	{
		// create a new node if path doesn't exists
		if (curr->character.find(ch) == curr->character.end())
			curr->character[ch] = getNewTrieNode();

		// go to next node
		curr = curr->character[ch];
	}

	curr->isLeaf = true;
}

// Function to find Longest Common Prefix
string findLCP(string dict[], int n)
{
	// insert all keys into trie
	Trie* head = getNewTrieNode();
	for (int i = 0; i < n; i++)
		insert(head, dict[i]);

	// traverse the trie and find Longest Common Prefix

	string lcp = "";
	Trie* curr = head;

	// do till we find a leaf node or node has more than 1 children
	while (curr && !curr->isLeaf && (curr->character.size() == 1))
	{
		// get iterator to only child
		auto it = curr->character.begin();
		
		// append current char to LCP
		lcp += it->first;
		
		// update curr pointer to child node
		curr = it->second;
	}
	
	return lcp;
}

int main()
{
	// given set of keys
	string dict[] = 
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codependence", "codependency", "codependent",
		"codependents", "codes", "codesign", "codesigned", "codeveloped", 
		"codeveloper", "codex", "codify", "codiscovered", "codrive"
	};
	
	// number of keys
	int n = sizeof(dict)/sizeof(dict[0]);

	cout << "Longest Common Prefix is " << findLCP(dict, n) << endl;

	return 0;
}
