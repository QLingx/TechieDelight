#include <bits/stdc++.h>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "nullptr\n";
}

// Helper function to insert a new node in the beginning of the linked list
void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *headRef;

	*headRef = newNode;
}

// Function that takes the node from the front of the source, and move it
// to the front of the destination
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
	// if the source list empty, do nothing
	if (*sourceRef == nullptr)
		return;

	struct Node* newNode = *sourceRef;	// the front source node

	*sourceRef = (*sourceRef)->next;	// Advance the source pointer

	newNode->next = *destRef;			// Link the old dest off the new node
	*destRef = newNode;					// Move dest to point to the new node
}

// Function to construct a linked list by merging alternate nodes of two
// given linked lists by using Local References and MoveNode() as helper
void merge(struct Node* &a, struct Node* &b)
{
    struct Node* result = nullptr;
    struct Node** lastPtrRef = &result;

	while (1)
	{
        if (a == nullptr)
		{
            *lastPtrRef = nullptr;  // Note
            break;
        }
        else if (b == nullptr)
		{
            *lastPtrRef = a;
            break;
        }
        else
		{
            MoveNode(lastPtrRef, &a);
            lastPtrRef = &((*lastPtrRef)->next);

            MoveNode(lastPtrRef, &b);
            lastPtrRef = &((*lastPtrRef)->next);
        }
    }

    a = result;
}

// main method
int main()
{
	struct Node *a = nullptr, *b = nullptr;

    // construct first list
	for (int i = 3; i >= 0; i--)
		push(&a, i);

    // construct second list
	for (int i = 10; i >= 4; i--)
		push(&b, i);

	// print both linked list
	cout << "First List  - "; printList(a);
	cout << "Second List - "; printList(b);

	merge(a, b);

	cout << "\nAfter Merge - \n\n";

	cout << "First List  - "; printList(a);
	cout << "Second List - "; printList(b);

	return 0;
}
