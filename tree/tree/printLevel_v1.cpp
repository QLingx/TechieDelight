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

// Function to print level order traversal of given binary tree
void levelOrderTraversal(Node* root)
{
    // create an empty queue and enqueue root node
    list<Node*> queue;
	queue.push_back(root);

    // pointer to store current node
	Node* curr = nullptr;

    // run till queue is not empty
	while (queue.size())
	{
		// process each node in queue and enqueue their
		// non-empty left and right child to queue
		curr = queue.front();
		queue.pop_front();

		cout << curr->key << " ";

		if (curr->left)
			queue.push_back(curr->left);

		if (curr->right)
			queue.push_back(curr->right);
	}
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

	levelOrderTraversal(root);

	return 0;
}
