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

// Function to print Spiral order traversal of given binary tree
void spiralOrderTraversal(Node* root)
{
	if (root == nullptr)
		return;

    // create an empty double ended queue and enqueue root node
	list<Node*> deque;      // or use deque
	deque.push_front(root);

	// flag used to differentiate between odd or even level
	bool flag = false;

    // run till deque is not empty
    while (!deque.empty())
	{
		// calculate number of nodes in current level
		int nodeCount = deque.size();

		// print left to right
		if (flag)
		{
            // process each node of current level and enqueue their
            // non-empty left and right child to deque
			while (nodeCount)
			{
			    // pop from front if flag is true
				Node* curr = deque.front();
				deque.pop_front();

				cout << curr->key << " ";

				// push left child to end followed by right child if flag is true

				if (curr->left != nullptr)
					deque.push_back(curr->left);

				if (curr->right != nullptr)
					deque.push_back(curr->right);

				nodeCount--;
			}
		}

		// print right to left
		else
		{
            // process each node of current level and enqueue their
            // non-empty right and left child to queue
			while (nodeCount)
			{
			    // Important - pop from back if flag is false
				Node* curr = deque.back();
				deque.pop_back();

				cout << curr->key << " ";   // print front node

				// Important - push right child to front followed by left
				// child if flag is false

				if (curr->right != nullptr)
					deque.push_front(curr->right);

				if (curr->left != nullptr)
					deque.push_front(curr->left);

				nodeCount--;
			}
		}

		// flip the flag for next level
		flag = !flag;
		cout << endl;
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

	spiralOrderTraversal(root);

	return 0;
}
