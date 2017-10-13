#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node#include <bits/stdc++.h>
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

// Iterative function to perform in-order traversal of the tree
void inorderIterative(Node *root)
{
	// create an empty stack
	stack<Node*> stack;

	// start from root node (set current node to root node)
	Node *curr = root;

    // if current node is null and stack is also empty, we're done
	while (!stack.empty() || curr != nullptr)
	{
	    // if current node is not null, push it to the stack (defer it)
	    // and move to its left child
		if (curr != nullptr)
		{
			stack.push(curr);
			curr = curr->left;
		}
		else
		{
            // else if current node is null, we pop an element from the stack,
            // print it and finally set current node to its right child
			curr = stack.top();
			stack.pop();
			cout << curr->data << " ";

			curr = curr->right;
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

	inorderIterative(root);

	return 0;
}

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

// Recursive function to perform in-order traversal of the tree
void inorder(Node *root)
{
    // return if the current node is empty
	if (root == nullptr)
		return;

    // Traverse the left subtree
	inorder(root->left);

    // Display the data part of the root (or current node)
	cout << root->data << " ";

    // Traverse the right subtree
    inorder(root->right);
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

	inorder(root);

	return 0;
}
