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

// Take the node from the front of the source, and move it to the front of the destination.
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
    // if the source list empty, do nothing
    if (*sourceRef == nullptr)
        return;

    struct Node* newNode = *sourceRef;  // the front source node

    *sourceRef = (*sourceRef)->next;    // Advance the source pointer

    newNode->next = *destRef;           // Link the old dest off the new node
    *destRef = newNode;                 // Move dest to point to the new node
}

// Function to rearrange the given list such that every even node will be
// moved to end of the list in reverse order. Note that head is not passed
// by reference as first node will remain the same place
void rearrange(struct Node* head)
{
    // empty list
    if (head == nullptr)
        return;

    // maintain two lists odd and even
    struct Node *odd = head;
    struct Node *even = nullptr, *prev = nullptr;

    // do for each odd node
    while (odd && odd->next)
	{
	    // "move" next node (which will be even) to the front of even list
        MoveNode(&even, &(odd->next));

        // update prev and move to next odd node
        prev = odd;
        odd = odd->next;
    }

    // append even list to odd list
    if (odd)
        odd->next = even;
    else
        prev->next = even;
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

    cout << "Before - ";
    printList(head);

    // rearrange the pointers of given list
    rearrange(head);

    cout << "After  - ";
	printList(head);

    return 0;
}
