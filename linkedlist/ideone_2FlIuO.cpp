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

// Recursive function to split given linked list into two lists where
// each list containing alternating elements from the original list.
// The solution maintains the same order as the source list
void AlternatingSplit(struct Node* odd, struct Node* even)
{
    if (odd == nullptr || even == nullptr)
		return;

    if (odd->next)
		odd->next = odd->next->next;

    if (even->next)
		even->next = even->next->next;

    AlternatingSplit(odd->next, even->next);
}

/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
void AlternatingSplit(struct Node* source, struct Node** aRef,
					struct Node** bRef)
{
    *aRef = source;
    *bRef = source->next;
    AlternatingSplit(*aRef, *bRef);
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

	struct Node *a = nullptr, *b = nullptr;
	AlternatingSplit(head, &a, &b);

	// print both linked list
	cout << "First List  - ";
	printList(a);

	cout << "Second List - ";
	printList(b);

	return 0;
}
