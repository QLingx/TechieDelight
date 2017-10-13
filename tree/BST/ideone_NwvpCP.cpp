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

// Iterative function to search a given key in root
bool search(Node *root, int key)
{
    // traverse the tree and search for the key
	while (root)
	{
        // if given key is less than the current node, go to left subtree
        // else go to right subtree

		if (key < root->data)
			root = root->left;
		else if (key > root->data)
			root = root->right;

        // if key is found return true
		else
			return true;
	}

	// we reach here if the key is not present in the BST
	return false;
}

// Recursive function to find Lowest Common Ancestor of given nodes
// x and y where both x and y are present in the Binary Search Tree
Node *LCARecursive(Node* root, int x, int y)
{
    // base case: empty tree
	if (root == nullptr)
		return nullptr;

    // if both x and y is smaller than root, LCA exists in left subtree
	if (root->data > max(x, y))
		return LCARecursive(root->left, x, y);

    // if both x and y is greater than root, LCA exists in right subtree
	else  if (root->data < min(x, y))
		return LCARecursive(root->right, x, y);

    // if one key is greater (or equal) than root and one key is smaller
    // (or equal) than root, then the current node is LCA
	return root;
}

// Print Lowest Common Ancestor of two nodes in a BST
void LCA(Node* root, int x, int y)
{
    // return if tree is empty or either x or y is not present in the tree
	if(root == nullptr || !search(root, x) || !search(root, y))
		return;

	// lca stores lowest common ancestor of x and y
    Node* lca = LCARecursive(root, x, y);

    // if lowest common ancestor exists, print it
	if (lca != nullptr)
		cout << "LCA is " << lca->data << endl;
	else
		cout << "LCA do not exist\n";
}

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
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	LCA(root, 8, 12);

	return 0;
}
