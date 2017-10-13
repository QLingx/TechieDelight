#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
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

// Function to print pre-order traversal of given tree
void preorder(Node* root)
{
	if (root == nullptr)
		  return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

// Recursive function to in-place convert the given binary tree to its
// sum tree by traversing the tree in postorder manner
int convertToSumTree(Node *root)
{
    // base case: tree is empty
	if (root == nullptr)
		return 0;

    // recursively convert left and right subtree first before
    // processing the root node
	int left = convertToSumTree(root->left);
	int right = convertToSumTree(root->right);

	// stores current value of root node
	int old = root->data;

	// update root to sum of left and right subtree
	root->data = left + right;

	// return the updated value plus old value (sum of tree rooted at root node)
	return root->data + old;
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4}, {"RL", 5}, {"RR", 6},
		{"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	convertToSumTree(root);
	preorder(root);

	return 0;
}
