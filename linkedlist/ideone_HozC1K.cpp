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

// Recursive function to return K'th node from the end in a linked list
int getKthFromtheEnd(Node* node, int k)
{
    // base case
    if (node == nullptr)
        return 0;

    int count = getKthFromtheEnd(node->next, k) + 1;

    if (count == k)
        cout << "K'th node from the end is " << node->data;

    return count;
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(head, keys[i]);

	int k = 3;
    getKthFromtheEnd(head, k);

    return 0;
}
