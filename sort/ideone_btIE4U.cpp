#include <bits/stdc++.h>
using namespace std;

// define character size
// Trie supports lowercase English characters (a - z)
#define CHAR_SIZE 26

// A Trie node
struct Trie
{
    string key;	// set when node is a leaf node
	Trie* character[CHAR_SIZE];
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;

	for (int i = 0; i < CHAR_SIZE; i++)
		node->character[i] = NULL;

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
		if (curr->character[*str - 'a'] == NULL)
			curr->character[*str - 'a'] = getNewTrieNode();

		// go to next node
		curr = curr->character[*str - 'a'];

		// move to next character
		str++;
	}

	// store key in leaf node
	curr->key = key;
}

// Function to perform pre-order traversal of given Trie
bool preorder(Trie* curr)
{
	// return false if Trie is empty
    if(curr == NULL)
        return false;

	for (int i = 0; i < CHAR_SIZE; i++)
	{
		if (curr->character[i] != NULL)
        {
        	// if leaf node, print key
            if (curr->character[i]->key.length() != 0)
                cout << curr->character[i]->key << endl;

			preorder(curr->character[i]);
        }
	}
}

int main()
{
	Trie* head = getNewTrieNode();

	// given set of keys
	char *dict[] = 
	{
		"lexicographic", "sorting", "of", "a", "set", "of", "keys", "can", "be",
		"accomplished", "with", "a", "simple", "trie", "based", "algorithm", 
		"we", "insert", "all", "keys", "in", "a", "trie", "output", "all", 
		"keys", "in", "the", "trie", "by", "means", "of", "preorder", 
		"traversal", "which", "results", "in", "output", "that", "is", "in", 
		"lexicographically", "increasing", "order", "preorder", "traversal", 
		"is", "a", "kind", "of", "depth", "first", "traversal"
	};
	
	// size of the dictionary
    int n = sizeof(dict)/sizeof(dict[0]);

	// insert all keys of dictionary into trie
	for (int i = 0; i < n; i++)
        insert(head, dict[i]);

	// print keys in lexicographic order
	preorder(head);

	return 0;
}
