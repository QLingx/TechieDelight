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

// Function to determine if two given binary trees can be transformed
// to each other by doing any number of swaps of left and right subtree
bool equal(Node* X, Node* Y)
{
    // base case: both trees are same (handles case when both trees are empty)
	if (X == Y)
		return true;

    return (X && Y) && (X->data == Y->data) &&
		((equal(X->left, Y->left) && equal(X->right, Y->right)) ||
		(equal(X->right, Y->left) && equal(X->left, Y->right)));
}

// main function
int main()
{
    // construct first tree
    Node* X = nullptr;
	vector<pair<string, int>> x =
	{
		 {"", 6}, {"L", 3}, {"R", 8}, {"LL", 1}, {"LR", 7}, {"RL", 4},
		 {"RR", 2}, {"RLL", 1}, {"RLR", 7}, {"RRR", 3}
	};

	for (auto pair: x)
		insert(X, pair.first, pair.second);


    // construct second tree
	Node* Y = nullptr;
	vector<pair<string, int>> y =
	{
		 {"", 6}, {"L", 8}, {"R", 3}, {"LL", 2}, {"LR", 4}, {"RL", 7},
		 {"RR", 1}, {"LLL", 3}, {"LRL", 1}, {"LRR", 7}
	};

	for (auto pair: y)
		insert(Y, pair.first, pair.second);


	equal(X, Y)? cout << "Yes": cout << "No";

	return 0;
}
