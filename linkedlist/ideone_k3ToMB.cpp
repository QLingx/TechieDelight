#include <iostream>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
    int data;
    Node* next;
};

// Helper function to create a new node with the given data and
// pushes it onto the front of the list
void push(Node*& headRef, int data)
{
    // create a new linked list node from heap
    Node* newNode = new Node;

    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}

// Helper function to print given linked list
void printList(Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
    	cout << ptr->data << " -> ";
    	ptr = ptr->next;
    }

    cout << "null";
}

void sortList(struct Node * &head)
{
	// base case
	if (head == nullptr || head->next == nullptr)
        return;

	// maintain three dummy nodes
	struct Node dummyZero, dummyOne, dummyTwo;
	dummyZero.next = dummyOne.next = dummyTwo.next = nullptr;

	// maintain three pointers
	struct Node *zero = &dummyZero, *one = &dummyOne, *two = &dummyTwo;
	struct Node* curr = head;

	// traverse the list
	while (curr != nullptr)
	{
		if (curr->data == 0)
		{
			zero->next = curr;
			zero = zero->next;
		}
		else if (curr->data == 1)
		{
			one->next = curr;
			one = one->next;
		}
		else
		{
			two->next = curr;
			two = two->next;
		}
        curr = curr->next;
	}

	// combine lists containing 0's, 1's and 2's
	zero->next = (dummyOne.next)? (dummyOne.next): (dummyTwo.next);
	one->next = dummyTwo.next;
	two->next = nullptr;

	// change head
	head = dummyZero.next;
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 0, 0, 1, 2, 1, 2, 1 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(head, keys[i]);

    sortList(head);

    printList(head);

    return 0;
}
