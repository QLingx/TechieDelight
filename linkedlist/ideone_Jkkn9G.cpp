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

// Iterative function to return K'th node from the end in a linked list
Node* getKthFromtheEnd(Node* head, int k)
{
    int n = 0;
    Node* curr = head;
    
    // Count number of nodes in the linked list
    while (curr) 
    {
        curr = curr->next;
        n++;
    }

	// if number of nodes is more than or equal to K
    if (n >= k)
    {
		// return (n-k+1)th node from the beginning
	    curr = head;
		for (int i = 0; i < n - k; i++)
	        curr = curr->next;
    }

    return curr;
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
    Node* node = getKthFromtheEnd(head, k);
    
    if (node)
    	cout << "K'th node from the end is " << node->data;
 
    return 0;
}
