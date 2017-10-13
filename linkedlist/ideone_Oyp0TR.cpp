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

    cout << "nullptr";
}

// Helper function to insert a new node in the beginning of the linked list
void push(struct Node** headRef, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to remove duplicates from a sorted list
void RemoveDuplicates(struct Node* head)
{
	struct Node* previous = nullptr;
	struct Node* current = head;

	// take an empty set to store linked list nodes for future reference
	unordered_set<int> set;

	// do till linked list is not empty
	while (current != nullptr)
	{
	    // if current node is seen before, delete it
		if (set.find(current->data) != set.end())
		{
			previous->next = current->next;
			delete current;
		}
        else
        {
            // insert current node into the set and proceed to next node
            set.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
}

// main method
int main()
{
    // input keys
	int keys[] = {5, 3, 4, 2, 5, 4, 1, 3};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

    RemoveDuplicates(head);

	// print linked list
    printList(head);

    return 0;
}
