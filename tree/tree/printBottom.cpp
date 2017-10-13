#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Function to insert given key into the tree
void insert(Node*& root, string level, int key)
{
	// tree is empty
	if (level.length() == 0)
	{
		root = newNode(key);
		return;
	}

	int i = 0;
	Node* ptr = root;
	while (i < level.length() - 1)
	{
		if (level[i++] == 'L')
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	if (level[i] == 'L')
		ptr->left = newNode(key);
	else
		ptr->right = newNode(key);
}

// Recursive function to do a pre-order traversal of the tree and fill the map
// Here node has 'dist' horizontal distance from the root of the
// tree and level represent level of the node
void printBottom(Node *node, int dist, int level, auto &map)
{
    // base case: empty tree
	if (node == nullptr)
		return;

	// if current level is more than or equal to maximum level seen so far
	// for the same horizontal distance or horizontal distance is seen for 
	// the first time, update the map
	if (level >= map[dist].second)
	{
		// update value and level for current distance
		map[dist] = { node->key, level };
	}

    // recurse for left subtree by decreasing horizontal distance and
    // increasing level by 1
	printBottom(node->left, dist - 1, level + 1, map);

    // recurse for right subtree by increasing both level and
    // horizontal distance by 1
	printBottom(node->right, dist + 1, level + 1, map);
}

// Function to print the bottom view of given binary tree
void printBottom(Node *root)
{
    // create an empty map where
    // key -> relative horizontal distance of the node from root node and
    // value -> pair containing node's value and its level
	map<int, pair<int, int>> map;

	// do pre-order traversal of the tree and fill the map
	printBottom(root, 0, 0, map);

	// traverse the map and print bottom view
 	for (auto it: map)
		cout << it.second.first << " ";
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int> > keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4}, {"RL", 5},
		{"RR", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	printBottom(root);

	return 0;
}
