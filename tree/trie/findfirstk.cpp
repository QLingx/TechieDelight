#include <bits/stdc++.h>
using namespace std;

// A Trie node
struct Trie
{
	// count and key will be set only for leaf nodes
	// key stores the string and count stores its frequency so far
	int count;
	string key;

	// each node stores a map to its child nodes
	unordered_map<char, Trie*> character;
};

// A max-heap node
struct Node 
{
	string key;	
	int count;
};
 
// Comparison object used to order the max-heap
struct comp
{
	bool operator()(const Node lhs, const Node rhs) const
	{
		return lhs.count < rhs.count;
	}
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->count = 0;
	
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
	
	// store key and its count in leaf nodes
	curr->key = str;
	curr->count += 1;
}

// Function to perform pre-order traversal of Trie and insert
// each distinct key along with its count in max-heap
bool preorder(Trie* curr, auto &pq)
{
	// base condition
    if(curr == NULL)
        return false;
 
	for (auto it: curr->character)
	{
       	// if leaf node is reached (leaf node have non-zero count),
       	// push key with its frequency in max-heap
       	if (it.second->count)
			pq.push({ it.second->key, it.second->count });

		// recurse for current node children
		preorder(it.second, pq);
	}
}

// Function to find first k-maximum occurring words in given list of strings
void findKfrequentWords(string dict[], int n, int k)
{
	Trie* head = getNewTrieNode();
	
	// insert all keys into trie and maintain each key 
	// frequency in trie leaf nodes
	for (int i = 0; i < n; i++)
        insert(head, dict[i]);

	// create an empty max-heap
	priority_queue<Node, vector<Node>, comp> pq;

	// perform pre-order traversal of given Trie and push each 
	// unique key with its frequency in max-heap
	preorder(head, pq);
	
	// do till max-heap is not empty or k keys are not printed
	while (k-- && !pq.empty())
	{
		// extract the maximum node from the max-heap
		Node max = pq.top();
		pq.pop();
 
		// print the maximum occurring element with its count
		cout << setw(8) << max.key << " occurs " << max.count << " times\n";
	}
}

int main()
{
	// given set of keys
	string dict[] = 
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
	};

	int k = 4;

	// number of keys
    int n = sizeof(dict)/sizeof(dict[0]);

	findKfrequentWords(dict, n, k);

	return 0;
}