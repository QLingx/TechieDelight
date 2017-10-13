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

// Function to perform inorder traversal of the tree
void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Function to check if given node is a leaf node or not
bool isLeaf(Node* node)
{
	return (node->left == nullptr && node->right == nullptr);
}

// Main function to truncate given binary tree to remove nodes
// which lie on a path having sum less than k
void trunc(Node* &curr, int k, int sum)
{
    // base case: empty tree
	if (curr == nullptr)
		return;

    // update sum of nodes in path from root node to current node
	sum = sum + (curr->data);

	// Recursively truncate left and right subtrees
	trunc(curr->left, k, sum);
	trunc(curr->right, k, sum);

	// Since we are doing postorder traversal, it is possible that subtree rooted
	// at current node is already truncated and current node is a leaf now

	// if current node is a leaf node and its path from root node has sum
	// less than the required sum, remove it
	if(sum < k && isLeaf(curr))
	{
	    // free memory allocated to current node
		free(curr);

		// set current node to null (node is passed by reference)
		curr = nullptr;
	}
}

// Function to truncate given binary tree to remove nodes which lie on
// a path having sum less than k
void truncate(Node* &root, int k)
{
	int sum = 0;
	trunc(root, k, sum);
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
		  6
		/   \
	   /	 \
	  3       8
			/   \
		   /	 \
		  4	      2
		/   \      \
	   /	 \      \
	  1       7      3
	*/

	vector<pair<string, int>> keys =
	{
		{"", 6}, {"L", 3}, {"R", 8}, {"RL", 4}, {"RR", 2},
		{"RLL", 1}, {"RLR", 7}, {"RRR", 3}
	};

	int k = 20;
	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	truncate(root, k);
	inorder(root);

	return 0;
}
