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

// Function to find level of given node x
void Level(Node* root, Node* x, int index, int &level)
{
    // return if tree is empty or level is already found
	if (root == nullptr || level)
		return;

    // if given node is found, update its level
	if (root == x)
		level = index;

    // recurse for left and right subtree
	Level(root->left, x, index + 1, level);
	Level(root->right, x, index + 1, level);
}

void printLevel(Node* root, Node *node, int level)
{
    // base case
	if (root == nullptr)
		return;

    // print cousins
	if (level == 1)
	{
		cout << root->key << " ";
		return;
	}

    // recurse for left and right subtree if root is not parent of given node
	if (root->left && root->left != node &&
        root->right && root->right != node)
	{
		printLevel(root->left, node, level - 1);
		printLevel(root->right, node, level - 1);
	}
}

// Function to print all cousins of given node
void printAllCousins(Node *root, Node *node)
{
	int level = 0;

	// find level of given node
	Level(root, node, 1, level);

	// print all cousins of given node using its level number
	printLevel(root, node, level);
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7   */
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4},
		{"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	printAllCousins(root, root->right->left);

	return 0;
}
