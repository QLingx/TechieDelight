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

// Recursive function to construct a linked list by merging 
// alternate nodes of two given linked lists
struct Node* ShuffleMerge(struct Node* a, struct Node* b)
{
	// see if either list is empty
    if (a == nullptr)
        return b;

	if (b == nullptr)
        return a;

    // it turns out to be convenient to do the recursive call first --
    // otherwise a->next and b->next need temporary storage

    struct Node* recur = ShuffleMerge(a->next, b->next);

    struct Node* result = a;	// one node from a
    a->next = b;				// one from b
    b->next = recur;			// then the rest

    return result;
}

// main method
int main()
{	// input keys
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

	struct Node* head = ShuffleMerge(a, b);
	cout << "After Merge - ";
	printList(head);

	return 0;
}
