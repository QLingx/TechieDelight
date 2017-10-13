#include <iostream>
using namespace std;

// Data Structure to store a linked list node
struct Node 
{
	int data;
	Node* next;
};

// Helper function to return new linked list node from heap
Node* newNode(int key, Node *ptr)
{
	Node* node = new Node();
	node->data = key;
	node->next = ptr;

	return node;
}

// Helper function to create a new node with the given data and
// pushes it onto the front of the list
void push(Node*& headRef, int data)
{
	// create a new linked list node from heap
	Node* newNode = new Node;

	newNode->data = data;
	newNode->next = headRef;
	headRef = newNode;
}

// Helper function to print given linked list
void printList(Node* head)
{
	Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "null";
}

// Rearrange the linked list so that it has alternating high, low values
void rearrange(Node *head)
{
	// empty list
	if (head == nullptr)
		return;

	Node* prev = head;
	Node* curr = head->next;

	// start from second node
	while (curr)
	{
		// If the prev node is greater than current node, swap their values
		if (prev->data > curr->data)
			swap(prev->data, curr->data);

		// if next node is greater than current node, swap their values
		if (curr->next && curr->next->data > curr->data)
			swap(curr->next->data, curr->data);

		// update prev and curr node
		prev = curr->next;

		if (!curr->next)
			break;

		curr = curr->next->next;
	}
}

// main method
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 6 };
	int n = sizeof(keys) / sizeof(keys[0]);

	Node* head = nullptr;
	for (int i = n - 1; i >= 0; i--)
		push(head, keys[i]);

	rearrange(head);

	printList(head);

	return 0;
}
