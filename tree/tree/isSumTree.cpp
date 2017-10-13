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

// Recursive function to check if given binary tree is a sum tree or not
int isSumTree(Node *root)
{
    // base case: empty tree
	if (root == nullptr)
		return 0;

    // special case: leaf node
	if (root->left == nullptr && root->right == nullptr)
        return root->key;

    // if root's value is equal to sum of all elements present in its
    // left and right subtree
	if (root->key == isSumTree(root->left) + isSumTree(root->right))
		return 2*root->key;

	return INT_MIN;
}

// main function
int main()
{
	Node* root = nullptr;
    /* Construct below tree
         44
        /  \
       /    \
      9     13
     / \    / \
    4   5  6   7   */
	vector<pair<string, int>> keys =
	{
		{"", 44}, {"L", 9}, {"R", 13},
		{"LL", 4}, {"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	if (isSumTree(root) != INT_MIN)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
