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
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = key;
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
    // Allocate the new node in the heap and set its data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

	// Set the .next pointer of the new node to point to the current
	// first node of the list.
    newNode->next = *headRef;

    // Change the head pointer to point to the new node, so it is
	// now the first node in the list.
    *headRef = newNode;
}

// Function to add a new node at the tail end of the list instead of the head
struct Node* appendNode(struct Node** headRef, int key)
{
    struct Node* current = *headRef;

    // special case for the empty list
    if (current == nullptr)
        push(headRef, key);
    else
    {
        // Locate the last node
        while (current->next != nullptr)
            current = current->next;

        // Build the node after the last node
        push(&(current->next), key);
    }
}

// main method
int main()
{
    // input keys
	int keys[] = {1, 2, 3, 4};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	for (int i = 0; i < n; i++)
		appendNode(&head, keys[i]);

	// print linked list
    printList(head);

    return 0;
}
