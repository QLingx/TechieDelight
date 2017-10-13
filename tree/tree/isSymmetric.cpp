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

// Function to check if subtree rooted at X and Y are mirror images
// of each other or not
bool isSymmetric(Node *X, Node *Y)
{
    // base case: if both tree are empty
	if (X == nullptr && Y == nullptr)
		return true;

    // return true if
    // 1. both trees are non-empty and
    // 2. left subtree is mirror image of right subtree and
    // 3. right subtree is mirror image of left subtree
	return (X != nullptr && Y != nullptr) &&
			isSymmetric(X->left, Y->right) &&
			isSymmetric(X->right, Y->left);
}

// Function to check if given binary Tree has a symmetric structure or not
bool isSymmetric(Node *root)
{
    // return true if left subtree and right subtree are
    // mirror images or each other
    return isSymmetric(root->left, root->right);
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	      3
	   \	 /
	    5   6     */
    vector<pair<string, int> > keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4}, {"RL", 5}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	isSymmetric(root)? cout << "Yes": cout << "No";

	return 0;
}
