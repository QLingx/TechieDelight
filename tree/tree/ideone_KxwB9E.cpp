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

// Function to store in-order traversal of the tree in a vector
void inorder(Node* node, vector<Node *> &vc)
{
	 if (node == nullptr)
		  return;

	 inorder(node->left, vc);
	 vc.push_back(node);
	 inorder(node->right, vc);
}

// Function to store post-order traversal of the tree in a vector
void postorder(Node* node, vector<Node *> &vc)
{
	 if (node == nullptr)
		  return;

	 postorder(node->left, vc);
	 postorder(node->right, vc);
	 vc.push_back(node);
}

// Function to check if given binary tree is a subtree of another
// binary tree or not
bool checkSubtree(Node *tree, Node *subtree)
{
    // base case: both trees are same
	if (tree == subtree)
		return true;

    // base case: if first tree is empty but second tree is non-empty
	if (tree == nullptr)
		return false;

    // store in-order traversal of both trees in v1 and v2 respectively
	vector<Node *> v1, v2;
	inorder(tree, v1);
	inorder(subtree, v2);

	// return false if v2 is not a sub-array of v1
	if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.end())
		return false;

    // reset both vectors
	v1.erase(v1.begin(), v1.end());
	v2.erase(v2.begin(), v2.end());

    // Now store post-order traversal of both trees in v1 and v2 respectively
	postorder(tree, v1);
	postorder(subtree, v2);

	// return false if v2 is not a sub-array of v1
    if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.end())
		return false;

    return true;
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7   */
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3},
		{"LL", 4}, {"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    checkSubtree(root, root->right)? cout << "Yes": cout << "No";

	return 0;
}
