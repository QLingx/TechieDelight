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

// Function to construct a linked list by merging alternate nodes of
// two given linked lists using dummy node
void merge(struct Node* &a, struct Node* &b)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = nullptr;

	while (1)
	{
        // empty list cases
		if (a == nullptr)
		{
            tail->next = nullptr;   // Note
            break;
        }

        else if (b == nullptr)
		{
            tail->next = a;
            break;
        }

        // common case: move two nodes to tail
		else
		{
            tail->next = a;
            tail = a;
            a = a->next;

            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    a = dummy.next;
}

// main method
int main()
{
	struct Node *a = nullptr, *b = nullptr;

    // construct first list
	for (int i = 3; i >= 0; i--)
		push(&a, i);

    // construct second list
	for (int i = 10; i >= 4; i--)
		push(&b, i);

	// print both linked list
	cout << "First List  - "; printList(a);
	cout << "Second List - "; printList(b);

	merge(a, b);

	cout << "\nAfter Merge - \n\n";

	cout << "First List  - "; printList(a);
	cout << "Second List - "; printList(b);

	return 0;
}
