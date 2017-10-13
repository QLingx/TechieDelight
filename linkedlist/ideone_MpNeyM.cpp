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

// Iterate through the list and move/insert each node to the front of 
// the result list like a Push of the node
static void reverse(struct Node** headRef)
{
    struct Node* result = nullptr;
    struct Node* current = *headRef;

	// traverse the list
	while (current != nullptr)
	{
		// tricky: note the next node
        struct Node* next = current->next;

		// move the current node onto the result
        current->next = result;
        result = current;

		// process next node
        current = next;
    }

	// fix head pointer
    *headRef = result;
}

// main method
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *head = nullptr;
	for (int i = n - 1; i >=0; i--)
		push(&head, keys[i]);

	reverse(&head);

	printList(head);

	return 0;
}
