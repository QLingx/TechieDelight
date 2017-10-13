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

// Recursive function to delete every n nodes in a linked list after 
// skipping m nodes
void deleteNodes(struct Node *head, int m, int n)
{
    // base case
    if (head == nullptr || head->next == nullptr)
        return;

    struct Node *prev = nullptr, *next = nullptr;
    struct Node *curr = head;

	// skip m nodes
    for (int i = 1; curr && i <= m; i++)
    {
        prev = curr;
        curr = curr->next;
    }

	// delete next n nodes
    for (int i = 1; curr && i <= n; i++)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }

    // link remaining nodes with last node
    prev->next = curr;

    // recurse for remaining nodes
    deleteNodes(curr, m, n);
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(head, keys[i]);

    deleteNodes(head, 1, 3);

    printList(head);

    return 0;
}
