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

// Helper function to find maximum value node in given BST
Node* findMaximum(Node* root)
{
	while (root->right)
		root = root->right;

	return root;
}

// Recursive function to find in-order predecessor for given key in a BST
// Note that predecessor 'prec' is passed by reference to the function
void findPredecessor(Node* root, Node*& prec, int key)
{
    // base case
	if (root == nullptr)
		return;

    // if node with key's value is found, the predecessor is maximum value
    // node in its left subtree (if any)
	if (root->data == key)
	{
		if (root->left)
			prec = findMaximum(root->left);
	}

    // if given key is less than the root node, recuse for left subtree
	else if (key < root->data)
	{
		findPredecessor(root->left, prec, key);
	}

    // if given key is more than the root node, recuse for right subtree
	else
	{
	    // update predecessor to current node before recursing in right subtree
		prec = root;
		findPredecessor(root->right, prec, key);
	}
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
	8	 12 16   25
	*/

	int keys[] = { 8, 10, 12, 15, 16, 20, 25 };

	for (int key : keys)
		root = insert(root, key);

    // find in-order predecessor for each key
	for (int key : keys)
	{
		cout << key << " ";

		Node* prec = nullptr;
		findPredecessor(root, prec, key);

		if (prec != nullptr)
			cout << "Predecessor is " << prec->data << endl;
		else
			cout << "No Predecessor\n";
	}
	return 0;
}
