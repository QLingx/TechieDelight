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

	cout << "null\n";
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

// Function to merge two sorted lists in reverse order
struct Node* mergeReverse(struct Node* a, struct Node* b)
{
    struct Node* result = nullptr;

    while (a && b)
	{
        if (a->data < b->data)
            MoveNode(&result, &a);
        else
            MoveNode(&result, &b);
    }

    while (b)
        MoveNode(&result, &b);

    while (a)
        MoveNode(&result, &a);

    return result;
}

// main method
int main()
{
	struct Node *a = nullptr, *b = nullptr;

	for (int i = 6; i > 0; i = i - 2)
		push(&a, i);

	for (int i = 9; i >= 1; i = i - 2)
		push(&b, i);

	// print both linked list
	cout << "First List  - ";
	printList(a);

	cout << "Second List - ";
	printList(b);

	Node *head = mergeReverse(a, b);

	cout << "\nAfter Merge - ";
	printList(head);

	return 0;
}
