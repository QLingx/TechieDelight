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

// Iterative function to perform post-order traversal of the tree
void postorderIterative(Node* root)
{
	// create an empty stack and push root node
	stack<Node*> stk;
	stk.push(root);

	// create another stack to store postorder traversal
    stack<int> out;

    // run till stack is not empty
	while (!stk.empty())
	{
	    // we pop a node from the stack and push the data to output stack
		Node *curr = stk.top();
		stk.pop();

		out.push(curr->data);

		// push left and right child of popped node to the stack
		if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}

	// print postorder traversal
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
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

	postorderIterative(root);

	return 0;
}
