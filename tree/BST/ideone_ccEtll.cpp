#include <iostream>
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

// Recursive function to search in given BST
void search(Node* root, int key, Node* parent)
{
	// if key is not present in the key
	if (root == nullptr)
	{
		cout << "Key Not found";
		return;
	}

	// if key is found
	if (root->data == key)
	{
		if (parent == nullptr)
			cout << "The node with key " << key << " is root node";

		else if (key < parent->data)
			cout << "Given key is left node of node with key " 
				 << parent->data;

		else cout << "Given key is right node of node with key " 
				 << parent->data;

		return;
	}

	// if given key is less than the root node, recuse for left subtree
	// else recuse for right subtree

	if (key < root->data)
		return search(root->left, key, root);

	return search(root->right, key, root);
}

// Search given key in BST
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	search(root, 25, nullptr);

	return 0;
}