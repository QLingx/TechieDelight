#include <bits/stdc++.h>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to return new linked list node from heap
struct Node* newNode(int key)
{
	// Allocate the new node in the heap using malloc() and set its data
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = key;

	// Set the .next pointer of the new node to point to null
	node->next = nullptr;

	return node;
}

// Helper function to print given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
    	cout << ptr->data << " -> ";
    	ptr = ptr->next;
    }

    cout << "nullptr";
}

// Helper function to insert a new node in the beginning of the linked list
void push(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert given node into the correct sorted position in given list 
// sorted in increasing order using Local references strategy for the head end
void SortedInsert(struct Node** headRef, struct Node* newNode)
{
    struct Node** currentRef = headRef;
    while (*currentRef != nullptr && (*currentRef)->data < newNode->data)
        currentRef = &((*currentRef)->next);

    newNode->next = *currentRef;
    *currentRef = newNode;
}

// main method
int main()
{
    // input keys
	int keys[] = {2, 4, 6, 8};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

    SortedInsert(&head, newNode(5));
	SortedInsert(&head, newNode(9));
	SortedInsert(&head, newNode(1));

	// print remaining linked list
    printList(head);

    return 0;
}
