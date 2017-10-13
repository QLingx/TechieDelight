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

// Function to print all nodes of a given binary tree in
// specific order from bottom to top
void printNodes(Node* root)
{
    // return is tree is empty
	if (root == nullptr)
		return;

    // start with level 1 (of root node)
	int level = 1;

	// create an empty multi-map of integers (every key can be
    // associated with multiple values)
    map<int, vector<int>> map;

    // insert root node at first level
	map[level].push_back(root->key);

    // create an two empty queues and enqueue root's left and
    // right child respectively
	queue<Node *> Q1, Q2;
	Q1.push(root->left);
	Q2.push(root->right);

    // run till queue is not empty
	while (!Q1.empty())
	{
        // increment level by 1
		level++;

		// calculate number of nodes in current level
		int n = Q1.size();

		// process every node of current level
		while (n--)
		{
		    // pop front node from first queue and insert it into the map
			Node* x = Q1.front();
			Q1.pop();

			map[level].push_back(x->key);

			// push left and right child of x to first queue
			if (x->left)
				Q1.push(x->left);

			if (x->right)
				Q1.push(x->right);


		    // pop front node from second queue and insert it into the map
			Node* y = Q2.front();
            Q2.pop();

			map[level].push_back(y->key);

			// push right and left child of y to second queue
			if (y->right)
				Q2.push(y->right);

			if (y->left)
				Q2.push(y->left);
		}
	}

    // iterate through the map using reverse iterator and
	// print all nodes present in very level
	for (auto it = map.rbegin(); it != map.rend(); it++)
	{
		for (int i: it->second)
			cout << i << " ";
	}
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6},
		{"RR", 7}, {"LLL", 8}, {"LLR", 9}, {"LRL", 10}, {"LRR", 11},
		{"RLL", 12}, {"RLR", 13}, {"RRL", 14}, {"RRR", 15}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	printNodes(root);

	return 0;
}
