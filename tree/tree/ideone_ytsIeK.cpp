#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	string key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(string key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Function to print all leaf nodes of the binary tree
void print(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr && node->right == nullptr)
		cout<< node->key << " ";
    else
    {
        print(node->right);
        print(node->left);
    }
}

// Function to construct a binary tree where each leaf node contains
// one unique combination of words formed 
void construct(Node* root, int digit[], int i, int n)
{
    // Base case: empty tree
	if (root == nullptr || i == n)
		return;

	static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXVZ";

	// check if digit[i+1] exists
	if (i + 1 < n)
	{
	    // process current and next digit
		int sum = 10 * digit[i] + digit[i + 1];

		// if a valid character can be formed by both digits
		// create left child from it
		if (sum <= 26)
			root->left = newNode(root->key + alphabet[sum - 1]);

        // construct left subtree by remaining digits
        construct(root->left, digit, i + 2, n);
	}

	// process current digit and create right child from it
    root->right = newNode(root->key + alphabet[digit[i] - 1]);

    // construct right subtree by remaining digits
	construct(root->right, digit, i + 1, n);
}

// main function
int main()
{
	int digit[] = {1, 2, 2, 1};
	int n = sizeof(digit)/sizeof(digit[0]);

	// create an empty root
	Node *root = newNode("");

	// construct binary tree
	construct(root, digit, 0, n);

	print(root);

	return 0;
}
