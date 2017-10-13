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

// Iterative function to check if two given binary trees are identical or not
bool isIdentical(Node *x, Node *y)
{
    // if both trees are empty, return true
	if (x == nullptr && y == nullptr)
		return true;

    // if first tree is empty (& second tree is non-empty), return false
	if (x == nullptr)
		return false;

    // if second tree is empty (& first tree is non-empty), return false
	if (y == nullptr)
		return false;

    // create a stack to hold Node* pairs
	stack<pair<Node*, Node*>> stack;
	stack.push({x, y});

	// do till stack is not empty
	while (!stack.empty())
	{
	    // pop top pair from the stack and process it
		Node *x = stack.top().first;
		Node *y = stack.top().second;
		stack.pop();

		// if value of their root node don't match, return false
		if (x->key != y->key)
		   return false;

        // if left subtree of both x and y exists, push their addresses
        // to stack else return false if only one left child exists
		if (x->left && y->left)
			stack.push({x->left, y->left});
		else if (x->left || y->left)
			return false;

        // if right subtree of both x and y exists, push their addresses
        // to stack else return false if only one right child exists
		if (x->right && y->right)
			stack.push({x->right, y->right});
		else if (x->right || y->right)
			return false;
	}

	// if we reach here, both binary trees are identical
	return true;
}

// main function
int main()
{
	// construct first tree
	Node* x = nullptr;
	vector<pair<string, int> > x_keys =
	{
		{"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
		{"LR", 12}, {"RL", 16}, {"RR", 25}
	};

	for (auto pair: x_keys)
		insert(x, pair.first, pair.second);

	// construct second tree
	Node* y = nullptr;
	vector<pair<string, int> > y_keys =
	{
		{"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
		{"LR", 12}, {"RL", 16}, {"RR", 25}
	};

	for (auto pair: y_keys)
		insert(y, pair.first, pair.second);


	if (isIdentical(x, y))
		cout << "Given binary Trees are identical";
	else
		cout << "Given binary Trees are not identical";

	return 0;
}
