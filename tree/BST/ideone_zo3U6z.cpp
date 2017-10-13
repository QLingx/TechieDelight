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

// Function to traverse the binary tree and store its keys in a set
void extractKeys(Node *root, auto &set)
{
    // base case
	if (root == nullptr)
		return;

	extractKeys(root->left, set);
	set.insert(root->data);
	extractKeys(root->right, set);
}

// Function to put back keys in set in their correct order in BST
// by doing in-order traversal
void convertToBST(Node *root, auto &it)
{
	if (root == nullptr)
		return;

	convertToBST(root->left, it);

	root->data = *it;
	it++;

	convertToBST(root->right, it);
}

// main function
int main()
{
    /* Construct below tree
		   8
		 /   \
		/	  \
	   3	   5
	  / \	  / \
	 /   \   /   \
	10	  2 4     6   */

	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(10);
	root->left->right = newNode(2);
    root->right->left = newNode(4);
	root->right->right = newNode(6);

	// traverse the binary tree and store its keys in a set
	set<int> set;
	extractKeys(root, set);

	// put back keys present in set in their correct order in BST
	auto it = set.begin();
	convertToBST(root, it);

	// print the BST
	inorder(root);

	return 0;
}
