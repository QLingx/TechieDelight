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

// Recursive function to check if two given binary trees are identical or not
int isIdentical(Node* x, Node* y)
{
    // if both trees are empty, return true
	if (x == nullptr && y == nullptr)
		return 1;

    // if both trees are non-empty and value of their root node matches,
    // recurse for their left and right sub-tree
	return (x && y) && (x->key == y->key) &&
         isIdentical(x->left, y->left) &&
         isIdentical(x->right, y->right);
}

// main function
int main()
{
	// construct first tree
	Node* x = nullptr;
	vector<pair<string, int> > x_keys =
	{
		{"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
		{"LR", 12}, {"RL", 16}, {"RR", 25}
	};

	for (auto pair: x_keys)
		insert(x, pair.first, pair.second);


	// construct second tree
	Node* y = nullptr;
	vector<pair<string, int> > y_keys =
	{
		{"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
		{"LR", 12}, {"RL", 16}, {"RR", 25}
	};

	for (auto pair: y_keys)
		insert(y, pair.first, pair.second);


	if (isIdentical(x, y))
		cout << "Given binary Trees are identical";
	else
		cout << "Given binary Trees are not identical";

	return 0;
}
