#include <bits/stdc++.h>
using namespace std;

// Data Structure to store a linked list node
struct Node {
    int data;
    struct Node* next;
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
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *headRef;

    *headRef = node;
}

// Iterative function to reverse nodes of linked list
void reverse(struct Node** headRef)
{
    struct Node* result = nullptr;
    struct Node* current = *headRef;

	// Iterate through the list and move/insert each node to the
    // front of the result list (like a push of the node)
    while (current != nullptr)
	{
        // tricky: note the next node
        struct Node* next = current->next;

        // move the current node onto the result
        current->next = result;
        result = current;

        // process next node
        current = next;
    }

    // fix head pointer
    *headRef = result;
}

// Recursive function to check if two linked lists are equal or not
bool compare(struct Node* a, struct Node* b)
{
    // see if both list is empty
    if (a == nullptr && b == nullptr)
        return true;

    return a && b && (a->data == b->data) && compare(a->next, b->next);
}

// Function to split the linked list into two equal parts and return
// pointer to the second half
struct Node* findMiddle(struct Node* head, bool &odd)
{
    struct Node* prev = nullptr;
    struct Node *slow = head, *fast = head;

    // find middle pointer
    while (fast && fast->next)
	{
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // for odd nodes, fast still points to last node
    if (fast)
	    odd = true;

    // make next of prev node null
    prev->next = nullptr;

    // return mid node
    return slow;
}

// Function to check if linked list is palindrome or not
bool checkPalindrome(struct Node* head)
{
    // base case
    if (head == nullptr)
        return true;

    // flag to indicate if number of nodes in the linked list is
    // odd or not. It will be passed by reference to findMiddle()
    bool odd = false;

    // find second half of linked list
    struct Node* mid = findMiddle(head, odd);

    // if number of nodes is odd, advance mid
    if (odd)
        mid = mid->next;

    // reverse the second half
    reverse(&mid);

    // compare first and second half
    return compare(head, mid);
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 2, 1};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(&head, keys[i]);

    if (checkPalindrome(head))
        cout << "Linked list is Palindrome";
    else
        cout << "Linked list is not Palindrome";
 
    return 0;
}