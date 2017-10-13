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

// Recursive function to move last node to the front in a given Linked List
void rearrange(Node* &headRef, Node* prev, Node* curr)
{
    // if current node is last node
    if (curr->next == nullptr)
    {
    	// make it's next point to fist node
        curr->next = headRef;

		// set is previous node to point to null
        prev->next = nullptr;
        
        // change head pointer
        headRef = curr;

        return;
    }

    rearrange(headRef, curr, curr->next);
}

// Function to move last node to the front in a given Linked List
void rearrange(Node* &root)
{
	// if list contains atleast two nodes
    if (root && root->next)
	    rearrange(root, nullptr, root);
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
