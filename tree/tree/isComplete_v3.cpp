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

// Recursive function to check if given binary tree is complete tree or not
bool isComplete(Node* root, int i, int n)
{
    // return if tree is empty
   	if (root == nullptr)
		return true;

	if ((root->left && 2*i + 1 >= n) || !isComplete(root->left, 2*i + 1, n))
		return false;

	if ((root->right && 2*i + 2 >= n) || !isComplete(root->right, 2*i + 2, n))
		return false;

	return true;
}

// main function
int main()
{
	Node* root = nullptr;
    /* Construct below tree
		  1
		/   \
	   /	 \
	  2 	  3
	 / \	 / \
	4   5   6   7   */

	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    if (isComplete(root, 0, keys.size()))
        cout << "Given binary tree is a Complete Binary Tree";
	else
        cout << "Given binary tree is not a Complete Binary Tree";

	return 0;
}
