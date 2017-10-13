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

// Iterative function to insert an key into BST
void insertIterative(Node*& root, int key)
{
    // start with root node
	Node *curr = root;

	// pointer to store parent node of current node
	Node *parent = nullptr;

	// if tree is empty, create a new node and set root
	if (root == nullptr)
	{
		root = newNode(key);
		return;
	}

	// traverse the tree and find parent node of key
	while (curr != nullptr)
	{
	    // update parent node as current node
		parent = curr;

        // if given key is less than the current node, go to left subtree
        // else go to right subtree
        if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	// construct a new node and assign to appropriate parent pointer
	if (key < parent->data)
		parent->left = newNode(key);
	else
		parent->right = newNode(key);
}

// main function
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		insertIterative(root, key);

	inorder(root);

	return 0;
}
