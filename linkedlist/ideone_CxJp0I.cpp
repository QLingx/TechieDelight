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

// Iterative function to reverse first k nodes of linked list
struct Node* reverseK(struct Node* &current, int k)
{
    struct Node* result = nullptr;
    struct Node* prev = nullptr;
    int count = 0;

	// Iterate through the list and move/insert each node to the
    // front of the result list (like a push of the node)
	while (current && count++ < k)
	{
		// tricky: note the next node
        struct Node* next = current->next;

		// move the current node onto the result
        current->next = result;
        result = current;

        // update previous pointer to current node
        prev = current;

		// move to next node in the list
        current = next;
    }

    // return last processed node
    return prev;
}

// Function to reverse every group of k nodes in given linked list
void reverseInGroups(struct Node **headRef, int k)
{
    // base case
    if (*headRef == nullptr)
        return;

    // start with current node
    struct Node* current = *headRef;

    // reverse next k nodes
    struct Node* prev = reverseK(current, k);

    // recurse for remaining nodes
    reverseInGroups(&current, k);

    // fix head node
    (*headRef)->next = current;
    *headRef = prev;
}

// main method
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *head = nullptr;
	for (int i = n - 1; i >=0; i--)
		push(&head, keys[i]);

    reverseInGroups(&head, 3);

	printList(head);

	return 0;
}
