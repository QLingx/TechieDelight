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

// Perform in-order traversal of the array and fill array A[]
void inorder(Node* root, vector<bool> &A, int i)
{
	if (root == nullptr)
		return;

    // recurse with index 2i+1 for left node
	inorder(root->left, A, 2*i + 1);

	// mark index i as visited
	A[i] = true;

	// recurse with index 2i+2 for right node
	inorder(root->right, A, 2*i + 2);
}

// Function to check if given binary tree is complete binary tree or not
bool isComplete(Node* root, int n)
{
    // return if tree is empty
    if (root == nullptr)
		return true;

    // construct an auxiliary boolean array of size n
	vector<bool> A(n, false);

    // fill array A[]
	inorder(root, A, 0);

	// check if all positions in the array are filled or not
	for (int i = 0; i < n; i++)
		if (!A[i])
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

	vector<pair<string, int> > keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    if (isComplete(root, keys.size()))
        cout << "Given binary tree is a Complete Binary Tree";
	else
        cout << "Given binary tree is not a Complete Binary Tree";

	return 0;
}
