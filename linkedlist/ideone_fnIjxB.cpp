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

// Recursive function to reverse the given linked list. It reverses the
// given linked list by fixing the head pointer first and then .next
// pointers of very node in reverse order
void recursiveReverse(struct Node* head, struct Node** headRef)
{
    struct Node* first;
    struct Node* rest;

    // empty list base case
    if (head == nullptr)
       return;

    first = head;		// suppose first = {1, 2, 3}
    rest = first->next;	// rest = {2, 3}

    // base case: List has only one node
    if (rest == nullptr)
	{
		// fix the head pointer here
		*headRef = first;
         return;
	}

	// Recursively reverse the smaller {2, 3} case
	// after: rest = {3, 2}
    recursiveReverse(rest, headRef);

	// put the first elem on the end of the list
    rest->next = first;
    first->next = nullptr;	// (tricky step -- make a drawing)
}

// Reverse the given linked list. The function takes a pointer
// (reference) to the head pointer
void reverse(struct Node** headRef)
{
    recursiveReverse(*headRef, headRef);
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