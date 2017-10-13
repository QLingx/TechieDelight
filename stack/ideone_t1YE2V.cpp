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

	unsigned i = 0;
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

// Function to check if given node is a leaf node or not
bool isLeaf(Node* node)
{
	return (node->left == nullptr && node->right == nullptr);
}

void postorderIterative(Node* root)
{
	// create an empty stack to store a pair of tree node and 
	// its path from the root node
	stack<pair<Node*, string>> stk;

	// push root node
	stk.push(make_pair(root, ""));

	// loop till stack is not empty
	while (!stk.empty())
	{
		// we pop a node from the stack and push the data to output stack
		pair<Node*, string> p = stk.top();
		stk.pop();

		// fetch current node
		Node* curr = p.first;
		string path = p.second;

		// add current node to the existing path
		string delim = (path == "") ? "\n" : " -> ";
		string rootToNodePath = to_string(curr->data) + delim + path;

		// if leaf node, print the path
		if (isLeaf(curr))
            cout << rootToNodePath;

		// push left and right child of popped node to the stack
		if (curr->right)
			stk.push(make_pair(curr->right, rootToNodePath));

		if (curr->left)
			stk.push(make_pair(curr->left, rootToNodePath));
	}
}

// main function
int main()
{
    /* Construct below tree
           1
         /   \ 
        /     \
       /       \
      2         3
     / \       / \
    /   \     /   \
   4     5   6     7
            / \
           /   \
          8     9
    */

	vector<pair<string, int>> keys =
	{
        {"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6},
        {"RR", 7}, {"RLL", 8}, {"RLR", 9}
	};

	Node* root = nullptr;

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	postorderIterative(root);

	return 0;
}
