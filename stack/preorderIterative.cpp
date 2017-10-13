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

// Iterative function to perform pre-order traversal of the tree
void preorderIterative(Node *root)
{
    // return if tree is empty
    if (root == nullptr)
	   return;

	// create an empty stack and push root node
	stack<Node*> stack;
	stack.push(root);

	// start from root node (set current node to root node)
	Node* curr = root;

    // run till stack is not empty
	while (!stack.empty())
	{
	    // if current node is not null, print it and push its right child
	    // to the stack and move to its left child
		if (curr != nullptr)
		{
			cout << curr->data << " ";

			if (curr->right)
				stack.push(curr->right);

			curr = curr->left;
		}
        // else if current node is null, we pop a node from the stack
        // set current node to the popped node
		else
		{
			curr = stack.top();
			stack.pop();
		}
	}
}

// main function
int main()
{
    /* Construct below tree
          1
        /   \
       /     \
      2       3
     /      /  \
    /      /    \
   4      5      6
         / \
        /   \
       7     8
    */

	vector<pair<string, int>> keys =
	{
        {"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"RL", 5},
        {"RR", 6}, {"RLL", 7}, {"RLR", 8}
	};

	Node* root = nullptr;
	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	preorderIterative(root);

	return 0;
}
