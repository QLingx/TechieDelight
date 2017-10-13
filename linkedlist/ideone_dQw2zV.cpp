#include <iostream>
using namespace std;

// Data Structure to store a linked list node
struct Node {
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

// Function to move last node to the front in a given Linked List
void rearrange(Node* &headRef)
{
    // Proceed only when list is valid
    if (!headRef || !headRef->next)
        return;

    Node *ptr = headRef;

    // Move to second last node
    while (ptr->next->next)
        ptr = ptr->next;

    // Convert the list to circular list
    ptr->next->next = headRef;

    // Fix head pointer
    headRef = ptr->next;

    // break the chain
    ptr->next= nullptr;
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(head, keys[i]);

    rearrange(head);

    printList(head);

    return 0;
}
