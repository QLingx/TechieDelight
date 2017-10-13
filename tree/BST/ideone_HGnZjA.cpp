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

// Iterative function to search in given BST
void searchIterative(Node* root, int key)
{
	// start with root node
	Node *curr = root;

	// pointer to store parent node of current node
	Node* parent = nullptr;

	// traverse the tree and search for the key
	while (curr != nullptr && curr->data != key)
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

	// if key is not present in the key
	if (curr == nullptr)
	{
		cout << "Key Not found";
		return;
	}

	if (parent == nullptr)
		cout << "The node with key " << key << " is root node";

	else if (key < parent->data)
		cout << "Given key is left node of node with key " << parent->data;

	else
		cout << "Given key is right node of node with key " << parent->data;
}

// main function
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	searchIterative(root, 25);

	return 0;
}