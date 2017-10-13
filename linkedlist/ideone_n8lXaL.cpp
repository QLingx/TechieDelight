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

	cout << "null\n";
}

// Helper function to insert a new node in the beginning of the linked list
void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *headRef;

	*headRef = newNode;
}

// Function to rearrange the linked list in specific manner
void rearrange(Node** headRef)
{
	// empty list or one node
	if (*headRef == nullptr || (*headRef)->next == nullptr)
		return;

	// create two dummy nodes
	Node dummyFirst, dummySecond;
	Node *first = &dummyFirst, *second = &dummySecond;

	Node *curr = *headRef;
	
	// iterate through the list and process two nodes at a time
	while (curr != nullptr)
	{
		// move current node to first list
		first->next = curr;
		first = first->next;
		
		// move next node to second list
		if (curr->next != nullptr)
		{
			second->next = curr->next;
			second = second->next;
			curr = curr->next;
		}
		curr = curr->next;
	}

	// combine first list with second list
	first->next = dummySecond.next;
	second->next = nullptr;
	
	// fix head pointer
	*headRef = dummyFirst.next;
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(&head, keys[i]);

    rearrange(&head);

    printList(head);

	return 0;
}
