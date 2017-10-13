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

// Recursive function to print root-to-leaf path for a given leaf
void printPathRecursive(Node* curr, unordered_map<Node*, Node*> map)
{
	// base case : curr is root node (parent of root node is null)
	if (curr == nullptr)
		return;

	// recursively call parent node
	printPathRecursive(map[curr], map);
	cout << curr->data << (isLeaf(curr) ? "\n" : " -> ");
}

// Iterative function to print leaf-to-root path for a given leaf
// For printing root-to-leaf path, we can use printPathRecursive() or a stack 
void printPathIterative(Node* leafNode, unordered_map<Node*, Node*> map)
{
	// start from the leaf node
	Node* curr = leafNode;

	// loop till root node is reached and print each node in the path
	while (map[curr] != nullptr)
	{
		cout << curr->data << " -> ";
		curr = map[curr];
	}
	
	cout << curr->data << endl;
}

// Iterative function to print leaf to root path for every leaf node
void postorderIterative(Node* root)
{
	// create an empty stack
	stack<Node*> stk;

	// create an emty map to store (child, parent) pairs
	unordered_map<Node*, Node*> map;
	
	// parent of root node is null
	map[root] = nullptr;

	// push root node
	stk.push(root);

	// loop till stack is not empty
	while (!stk.empty())
	{
		// pop top node from the stack
		Node* curr = stk.top();
		stk.pop();

		// if leaf node is found, print the path
		if (isLeaf(curr))
		{
			// print leaf-to-root path for current leaf
			printPathIterative(curr, map);

			// print root-to-leaf path for current leaf
			// printPathRecursive(curr, map);
		}

		// push left and right child of popped node to the stack
        // include current node left and right child in a map
		if (curr->right)
		{
			stk.push(curr->right);
			map[curr->right] = curr;
		}
				
		if (curr->left)
		{
			stk.push(curr->left);
			map[curr->left] = curr;
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