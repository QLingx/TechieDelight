#include <bits/stdc++.h>
using namespace std;

// A Trie node
struct Trie
{
	// count and key will be set only for leaf nodes
	// key stores the string and count stores its frequency so far
	string key;
	int count;
	
	// each node stores a map to its child nodes
	unordered_map<char, Trie*> character;
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->count = 0;
	
	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie*& head, char* str)
{
    // start from root node
	Trie* curr = head;
	char* key = str;
	
	while (*str)
    {
        // create a new node if path doesn't exists
		if (curr->character.find(*str) == curr->character.end())
			curr->character[*str] = getNewTrieNode();

		// go to next node
		curr = curr->character[*str];

		// move to next character
		str++;
	}

	// store key and its count in leaf nodes	
	curr->key = key;
	curr->count += 1;
}

// Function to perform pre-order traversal of given Trie 
// and find word with maximum frequency
bool preorder(Trie* curr, int &max_count, string &key)
{
	// return false if Trie is empty
    if(curr == NULL)
        return false;
 
	for (auto it: curr->character)
	{
       	// leaf node have non-zero count
 		if (max_count < it.second->count )
 		{
 			key = it.second->key;
 			max_count = it.second->count;
 		}
 		
 		// recurse for current node children
		preorder(it.second, max_count, key);
	}
}

int main()
{
	// given set of keys
	char *dict[] = 
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
	};
	
	// number of keys
    int n = sizeof(dict)/sizeof(dict[0]);

	// insert all keys into trie
	Trie* head = getNewTrieNode();
	for (int i = 0; i < n; i++)
        insert(head, dict[i]);

	int count = 0;
	string key;

	// perform pre-order traversal of given Trie and find key 
	// with maximum frequency
	preorder(head, count, key);
	
	cout << "Word : " << key << endl;
	cout << "Count: " << count << endl;

	return 0;
}
