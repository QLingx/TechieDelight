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

// Takes two lists sorted in increasing order, and merge their nodes 
// together to make one big sorted list which is returned
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	// a dummy first node to hang the result on
    struct Node dummy;
    dummy.next = nullptr;

	// Points to the last result node -- so tail->next is the place
	// to add new nodes to the result.
	struct Node* tail = &dummy;

    while (1) 
	{
		// if either list runs out, use the other list
        if (a == nullptr) 
		{
            tail->next = b;
            break;
        }
        else if (b == nullptr) 
		{
            tail->next = a;
            break;
        }

        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);

        tail = tail->next;
    }

    return dummy.next;
}

// main method
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *a = nullptr, *b = nullptr;
	for (int i = n - 1; i >= 0; i = i - 2)
		push(&a, keys[i]);

    for (int i = n - 2; i >= 0; i = i - 2)
		push(&b, keys[i]);

	// print both linked list
	cout << "First List  - ";
	printList(a);

	cout << "Second List - ";
	printList(b);

	struct Node* head = SortedMerge(a, b);
	cout << "After Merge - ";
	printList(head);

	return 0;
}
