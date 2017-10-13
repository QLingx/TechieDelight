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

// Remove duplicates from a sorted list
void RemoveDuplicates(struct Node* head)
{
    // do nothing if the list is empty
    if (head == nullptr)
        return;

    struct Node* current = head;

    // Compare current node with next node
    while(current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            struct Node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        }
        else {
            current = current->next; // only advance if no deletion
        }
    }
}

// main method
int main()
{
    // input keys
	int keys[] = {1, 2, 2, 2, 3, 4, 4, 5};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

    RemoveDuplicates(head);

	// print linked list
    printList(head);

    return 0;
}
