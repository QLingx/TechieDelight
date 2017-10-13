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

// Iterative function to delete given binary tree
void deleteBinaryTree(Node* &root)
{
    // empty tree
	if (root == nullptr)
		return;

    // create an empty queue and enqueue root node
	queue<Node*> queue;
	queue.push(root);

	Node *front = nullptr;

    // run till queue is not empty
	while (!queue.empty())
	{
		// delete each node in the queue one by one after pushing their
		// non-empty left and right child to the queue
		front = queue.front();
		queue.pop();

		if (front->left)
			queue.push(front->left);

		if (front->right)
			queue.push(front->right);

        // Important - delete front node ONLY after enqueuing its children
		delete front;
	}

	// set root as NULL before returning
	root = nullptr;
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int> > keys =
	{
		{"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
		{"LR", 12}, {"RL", 16}, {"RR", 25}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);


    // delete entire tree
	deleteBinaryTree(root);

	if (root == nullptr)
		cout << "Tree Successfully Deleted";

	return 0;
}
