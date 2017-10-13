#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node {
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

// Function to perform in-order traversal of the tree
void inorder(Node* root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node an return it
	if (root == nullptr)
		return newNode(key);

    // if given key is less than the root node, recuse for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

    // if given key is more than the root node, recuse for right subtree
    else
		root->right = insert(root->right, key);

	return root;
}

// Function to find a pair with given sum in given BST
bool findPair(Node* root, int sum, auto &set)
{
    // base case
	if (root == nullptr)
		return false;

    // return true if pair is found in the left subtree else continue
    // processing the node
	if (findPair(root->left, sum, set))
		return true;

    // if pair is formed with current node, print the pair and return true
	if (set.find(sum - root->data) != set.end())
	{
		cout << "Pair found (" << sum - root->data << ", " << root->data << ")";
		return true;
	}

	// insert current node's value into the set
	else
    {
		set.insert(root->data);
    }

    // search in right subtree
	return findPair(root->right, sum, set);
}

// main function
int main()
{
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
	int n = sizeof(keys)/sizeof(keys[0]);

	Node* root = nullptr;
    for (int key : keys)
		root = insert(root, key);

    // find pair with given sum
	int sum = 28;

	// create an empty set
	unordered_set<int> set;

	if (!findPair(root, sum, set))
		cout << "Pair do not exists";

	return 0;
}
