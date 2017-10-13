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

/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
void AlternatingSplit(struct Node* source, struct Node** aRef, 
					struct Node** bRef)
{
	struct Node aDummy;
	struct Node* aTail = &aDummy; // points to the last node in 'a'
	aDummy.next = nullptr;

	struct Node bDummy;
	struct Node* bTail = &bDummy; // points to the last node in 'b'
	bDummy.next = nullptr;

	struct Node* current = source;

	while (current != nullptr)
	{
		MoveNode(&(aTail->next), &current); // add at 'a' tail
		aTail = aTail->next; 				// advance the 'a' tail
		if (current != nullptr)
		{
			MoveNode(&(bTail->next), &current);
			bTail = bTail->next;
		}
	}
	*aRef = aDummy.next;
	*bRef = bDummy.next;
}

// main method
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(keys)/sizeof(keys[0]);

	// construct first linked list
	struct Node* head = nullptr;
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

	struct Node *a = nullptr, *b = nullptr;
	AlternatingSplit(head, &a, &b);

	// print both linked list
	cout << "First List  - ";
	printList(a);

	cout << "Second List - ";
	printList(b);

	return 0;
}
