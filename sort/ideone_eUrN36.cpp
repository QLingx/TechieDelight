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

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
It uses the fast/slow pointer strategy
*/
void FrontBackSplit(struct Node* source, struct Node** frontRef,
					struct Node** backRef)
{
	// if length is less than 2, handle seperately
	if (source == nullptr || source->next == nullptr)
	{
		*frontRef = source;
		*backRef = nullptr;
		return;
	}

	struct Node* slow = source;
	struct Node* fast = source->next;

	// Advance 'fast' two nodes, and advance 'slow' one node
	while (fast != nullptr)
	{
		fast = fast->next;
		if (fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	// 'slow' is before the midpoint in the list, so split it in two
	// at that point.
	*frontRef = source;
	*backRef = slow->next;
	slow->next = nullptr;
}

void MergeSort(struct Node** headRef)
{
	// Base case -- length 0 or 1
	if (*headRef == nullptr || (*headRef)->next == nullptr)
		return;

	struct Node* a;
	struct Node* b;

    // Split head into 'a' and 'b' sublists
	FrontBackSplit(*headRef, &a, &b);

	// Recursively sort the sublists
	MergeSort(&a);
	MergeSort(&b);

	// answer = merge the two sorted lists together
	*headRef = SortedMerge(a, b);
}

// main method
int main()
{
	// input keys
	int keys[] = { 6, 8, 4, 3, 1, 9 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *head = nullptr;
	for (int i = 0; i < n; i++)
		push(&head, keys[i]);

    // sort the list
	MergeSort(&head);

	// print the sorted list
	printList(head);

	return 0;
}
