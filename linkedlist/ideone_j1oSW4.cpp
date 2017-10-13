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

// Compute a new sorted list that represents the intersection of the
// two given sorted lists. This solution uses the local reference
struct Node* SortedIntersect(struct Node* a, struct Node* b)
{
    struct Node* result = nullptr;
    struct Node** lastPtrRef = &result;

    // Advance comparing the first nodes in both lists.
    // When one or the other list runs out, we're done.
    while (a != nullptr && b != nullptr)
	{
		// found a node for the intersection
        if (a->data == b->data)
		{
            push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
		// advance the smaller list
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }

    return result;
}

// main method
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *a = nullptr;
	for (int i = n - 1; i >=0; i = i - 3)
		push(&a, keys[i]);

    struct Node *b = nullptr;
	for (int i = n - 1; i >=0; i = i - 2)
		push(&b, keys[i]);

    // print both linked list
	cout << "First List  - ";
	printList(a);

	cout << "Second List - ";
	printList(b);

	struct Node *head = SortedIntersect(a, b);

	cout << "\nAfter Intersection - ";
	printList(head);

	return 0;
}
