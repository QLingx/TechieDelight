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
struct Node* ShuffleMerge(struct Node* a, struct Node* b)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = nullptr;

	while (1)
	{
        // empty list cases
		if (a == nullptr)
		{
            tail->next = b;
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

    return dummy.next;
}


// main method
int main()
{
	// input keys
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
