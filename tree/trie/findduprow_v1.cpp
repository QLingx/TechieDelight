#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 5
#define N 5

// A Trie node
struct Trie
{
	bool isLeaf;	// set when node is a leaf node
	Trie* character[2];
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;

	node->character[0] = node->character[1] = NULL;
	node->isLeaf = false;

	return node;
}

// Iterative function to insert array in Trie.
bool insert(Trie*& head, bool* arr)
{
	// start from root node
	Trie* curr = head;

	for(int i = 0; i < N; i++)
	{
		// create a new node if path doesn't exists
		if (curr->character[arr[i]] == NULL)
			curr->character[arr[i]] = getNewTrieNode();

		// go to next node
		curr = curr->character[arr[i]];
	}

	// if row is inserted before, return false
	if (curr->isLeaf)
		return false;

	// mark leaf node and return true
	return curr->isLeaf = true;
	
}

int main()
{
	Trie* head = getNewTrieNode();

	bool mat[M][N] = 
	{
		{1, 0, 0, 1, 0},
		{0, 1, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0}		
	};

	// insert all rows of into trie
	for (int i = 0; i < M; i++)
		if (!insert(head, mat[i]))
			cout << "Duplicate row found: Row #" << i + 1 << endl;

	return 0;
}