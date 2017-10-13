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

// Function take the node from the front of the source, and move it
// to the front of the destination
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

// main method
int main()
{
    // input keys
	int keys[] = { 1, 2, 3 };
	int n = sizeof(keys)/sizeof(keys[0]);

	// construct first linked list
	struct Node* a = nullptr;
    for (int i = n-1; i >= 0; i--)
		push(&a, keys[i]);

	// construct second linked list
	struct Node* b = nullptr;
    for (int i = 0; i < n; i++)
		push(&b, 2*keys[i]);

    // move front node of the b, and move it to the front of the a
    MoveNode(&a, &b);

	// print both lists
    cout << "First List  - ";
    printList(a);

    cout << "Second List - ";
	printList(b);

    return 0;
}
