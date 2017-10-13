#include <bits/stdc++.h>
using namespace std;

// define character size
// currently Trie supports lowercase English characters (a - z)
#define CHAR_SIZE 26

// A Trie node
struct Node
{
	bool exist;		// true when node is a leaf node
	Node* next[CHAR_SIZE];
};

// Function that returns a new Trie node
Node* newTrieNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->exist = false;
	
	for (int i = 0; i < CHAR_SIZE; i++)
		node->next[i] = NULL;
	
	return node;
}

// Recursive function to delete Trie in postorder manner
void freeTrie(Node* node)
{
	if (!node)
		return;

	for (int i = 0; i < CHAR_SIZE; i++)
		freeTrie(node->next[i]);

	free(node);
}

// Iterative function to insert a string in Trie
void* insertTrie(Node* head, string str)
{
	// start from root node
	Node* node = head;

	// do for each character in the string
	for (int i = 0; i < str.length(); i++)
	{
		// create a new node if path doesn't exists
		if (node->next[str[i] - 'a'] == NULL)
			node->next[str[i] - 'a'] = newTrieNode();

		// go to next node
		node = node->next[str[i] - 'a'];
	}

	// mark last node as leaf
	node->exist = true;
}

// Function to determine if string can be segmented into a space-separated
// sequence of one or more dictionary words
bool wordBreak(Node* head, string str)
{
	// get length of the string
	int n = str.length();

	// good[i] is true if the first i characters of str can be segmented
	bool good[n + 1];
	memset(good, false, sizeof good);

	good[0] = true; // base case

	for (int i = 0; i < n; i++)
	{
		if (good[i])
		{
			Node* node = head;
			for (int j = i; j < n; j++)
			{
				if (!node)
					break;

				node = node->next[str[j] - 'a'];	

				// we can make [0, i] using our known decomposition,
				// and [i+1, j] using this string in trie
				if (node && node->exist)
					good[j + 1] = true;
			}
		}
	}

	/*
	for (int i = 0; i < n; i++)
		cout << str[i] << " ";
	cout << endl;

	for (int i = 1; i < n + 1; i++)
		cout << good[i] << " ";
	cout << endl;
	*/

	// good[n] would be true if all characters of str can be segmented
	return good[n];
}

// main function
int main()
{
	// vector of strings to represent dictionary
	vector<string> dict = { "this", "th", "is", "famous", "word", "break",
		"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "prob", "lem"};

	// use trie to store dictionary
	Node* t = newTrieNode();
	for (auto x : dict)
		insertTrie(t, x);

	// given string
	string str = "wordbreakproblem";

	// check if string can be segmented or not
	if (wordBreak(t, str))
		cout << "String can be segmented";
	else
		cout << "String can't be segmented";

	// deallocate trie memory
	freeTrie(t);

	return 0;
}