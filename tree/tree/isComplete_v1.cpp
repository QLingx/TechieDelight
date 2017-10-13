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

// Function to check if given Binary Tree is Complete or not
bool isComplete(Node* root)
{
    // return if tree is empty
	if (root == nullptr)
        return false;

    // create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

    // pointer to store current node
	Node* front = nullptr;

	// flag to mark end of full nodes
	bool flag = false;

    // run till queue is not empty
	while (queue.size())
	{
	    // pop front node from the queue
		front = queue.front();
		queue.pop_front();

        // if we have encountered a non-full node before and current node
        // is not a leaf, tree cannot be complete tree
        if (flag && (front->left || front->right))
                return false;

        // if left child is empty & right child exists, tree cannot be complete
        if (front->left == nullptr && front->right)
            return false;

        // if left child exists, enqueue it
        if (front->left)
			queue.push_back(front->left);

		// if current node is a non-full node, set flag to true
        else
            flag = true;


        // if right child exists, enqueue it
        if (front->right)
			queue.push_back(front->right);

		// if current node is a non-full node, set flag to true
        else
            flag = true;
	}

	return true;
}

// main function
int main()
{
	Node* root = nullptr;
		/* Construct below tree
		  1
		/   \
	   /	 \
	  2 	  3
	 / \	 / \
	4   5   6   7   */

	vector<pair<string, int> > keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    if (isComplete(root))
        cout << "Given binary tree is a Complete Binary Tree";
	else
        cout << "Given binary tree is not a Complete Binary Tree";

	return 0;
}
