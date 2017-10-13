#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
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

// Data structure to store a Binary Tree node along
// with its level and parent information
struct NodeInfo
{
	int key;
	int level;
	Node* parent;
};

// Perform in-order traversal of the binary tree and update x and y
void inorder(Node* root, Node *parent, int level, NodeInfo &x, NodeInfo &y)
{
    // base case: tree is empty
	if (root == nullptr)
		return;

    // traverse left subtree
	inorder(root->left, root, level + 1, x, y);

	// if first element is found, save its level and parent node
	if (root->key == x.key)
	{
		x.level = level;
		x.parent = parent;
	}

	// if second element is found, save its level and parent node
	if (root->key == y.key)
	{
		y.level = level;
		y.parent = parent;
	}

    // traverse right subtree
	inorder(root->right, root, level + 1, x, y);
}

// Function to determine if two given nodes are cousins of each other
bool iterative(Node* root, int elem1, int elem2)
{
    // return if tree is empty
	if (root == nullptr)
		return true;

	int level = 1;				// level of root is 1
	Node* parent = nullptr;		// parent of root is null

	NodeInfo x = {elem1, level, parent};
	NodeInfo y = {elem2, level, parent};

	// perform in-order traversal of the array and update x and y
	inorder(root, nullptr, 1, x, y);

	// return false if x and y have different level or same parent
	if (x.level != y.level || x.parent == y.parent)
		return false;

	return true;
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4},
		{"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	if (iterative(root, 5, 6))
        cout << "Given nodes are cousins";
    else
        cout << "Given nodes are not cousins";

	return 0;
}
