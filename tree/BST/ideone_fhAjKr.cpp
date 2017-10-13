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

// Recursive function to insert an key into BST using a reference parameter
void insert(Node* &root, int key)
{
    // if the root is null, create a new node an return it
	if (root == nullptr)
	{
		root = newNode(key);
		return;
	}

    // if given key is less than the root node, recuse for left subtree
    // else recuse for right subtree
	if (key < root->data)
		insert(root->left, key);
	else
		insert(root->right, key);
}

// main function
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		insert(root, key);

	inorder(root);

	return 0;
}
