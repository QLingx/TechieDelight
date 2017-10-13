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

// Iterative function to calculate height of given binary tree
// by doing level order traversal of the tree
int height(Node *root)
{
    // empty tree has height 0
	if (root == nullptr)
		return 0;

    // create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

	Node* front = nullptr;
	int height = 0;

    // do till queue is not empty
	while (!queue.empty())
	{
		// calculate number of nodes in current level
		int size = queue.size();

		// process each node of current level and enqueue their
		// non-empty left and right child to queue
		while (size--)
		{
			front = queue.front();
			queue.pop_front();

			if (front->left)
				queue.push_back(front->left);

			if (front->right)
				queue.push_back(front->right);
		}

        // increment height by 1 for each level
		height++;
	}

	return height;
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

	cout << "The height of the binary tree is " << height(root);


	return 0;
}
