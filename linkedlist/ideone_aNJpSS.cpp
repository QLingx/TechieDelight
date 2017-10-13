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

// Function to add a new node at the tail end of the list instead of the head
struct Node* appendNode(struct Node** headRef, int key)
{
    struct Node* current = *headRef;
    struct Node* node = newNode(key);

    // special case for length 0
    if (current == nullptr)
    {
        *headRef = node;
    }
    else
    {
        // Locate the last node
        while (current->next != nullptr)
            current = current->next;

        current->next = node;
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
