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

// Takes two lists sorted in increasing order, and merge their nodes 
// together to make one big sorted list which is returned
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	// Base cases
    if (a == nullptr)
        return b;
    
	else if (b == nullptr)
        return a;
    
	struct Node* result = nullptr;
   
    // Pick either a or b, and recur
    if (a->data <= b->data) 
	{
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else 
	{
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
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

	struct Node* head = SortedMerge(a, b);
	cout << "After Merge - ";
	printList(head);

	return 0;
}
