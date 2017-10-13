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

// Function to check if given node is present in binary tree or not
bool isNodePresent(Node* root, Node* node)
{
    // base case
	if (root == nullptr)
		return false;

    // if node is found, return true
	if (root == node)
		return true;

    // return true if node is found in the left subtree or right subtree
	return isNodePresent(root->left, node) ||
            isNodePresent(root->right, node);
}

// Function to find lowest common ancestor of given nodes x and y where 
// both x and y are present in the binary tree.
// The function returns true if x or y is found in subtree rooted at root
// lca -> stores LCA(x, y) and it is passed by reference to the function
bool findLCA(Node* root, Node* &lca, Node* x, Node* y)
{
    // base case 1: return false if tree is empty
	if (root == nullptr)
		return false;

    // base case 2: return true if either x or y is found
	if (root == x || root == y)
	{
		// set lca to current node
		lca = root;
		return true;
	}

    // recursively check if x or y exists in the left subtree
    bool left = findLCA(root->left, lca, x, y);

	// recursively check if x or y exists in the right subtree
    bool right = findLCA(root->right, lca, x, y);

    // if x is found in one subtree and y is found in other subtree,
    // update lca to current node
    if (left && right)
   		lca = root;

    // return true if x or y is found in either left or right subtree
    return left || right;
}

// Function to find lowest common ancestor of nodes x and y
void findLCA(Node* root, Node* x, Node* y)
{
    // lca stores lowest common ancestor
	Node *lca = nullptr;

	// call LCA procedure only if both x and y are present in the tree
	if (isNodePresent(root, y) && isNodePresent(root, x))
        findLCA(root, lca, x, y);

    // if LCA exists, print it
	if (lca != nullptr)
		cout << "LCA is " << lca->data << endl;
	else
		cout << "LCA do not exist\n";
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	      3
	   \	 / \
	    4   5   6
           / \
          7   8
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4},
		{"RL", 5}, {"RR", 6}, {"RLL", 7}, {"RRR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	findLCA(root, root->right->left->left, root->right->right);
	findLCA(root, root->right->left->left, newNode(10));
    findLCA(root, root->right->left->left, root->right->left->left);
    findLCA(root, root->right->left->left, root->right->left);
    findLCA(root, root->left, root->right->left);

	return 0;
}
