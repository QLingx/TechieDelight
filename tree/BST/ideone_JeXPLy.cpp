#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Search Tree node
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

// Function to perform inorder traversal of the tree
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

// Function to truncate the BST and remove nodes having keys
// outside valid range
Node* truncate(Node* root, int min, int max)
{
    // base case
	if (root == nullptr)
		return root;

    // recursively truncate left and right subtree first
	root->left = truncate(root->left, min, max);
	root->right = truncate(root->right, min, max);

	Node* curr = root;

	// if root's key is smaller than the minimum allowed, delete it
	if (root->data < min)
	{
		root = root->right;
		delete curr;
	}
	// if root's key is larger than the maximum allowed, delete it
    else if (root->data > max)
	{
		root = root->left;
		delete curr;
	}

	return root;
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
		  15
		 /   \
		/	  \
	   10	  20
	  / \	  / \
	 /   \   /   \
	8	12 16   25
	*/
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// [9, 12] is valid range
	root = truncate(root, 9, 12);

	inorder(root);

	return 0;
}
