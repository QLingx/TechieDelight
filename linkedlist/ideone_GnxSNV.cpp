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

// Recursive function to construct a linked list by merging
// alternate nodes of two given linked lists
struct Node* ShuffleMerge(struct Node* a, struct Node* b)
{
    // see if either list is empty
    if (a == nullptr)
        return b;

    if (b == nullptr)
        return a;

    // it turns out to be convenient to do the recursive call first --
    // otherwise a->next and b->next need temporary storage

    struct Node* recur = ShuffleMerge(a->next, b->next);

    struct Node* result = a;	// one node from a
    a->next = b;				// one from b
    b->next = recur;			// then the rest

    return result;
}

// Function to split the linked list into two equal parts and return
// pointer to the second half
struct Node* findMiddle(struct Node* head)
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

    // for odd nodes, fix middle
    if (fast && fast->next == nullptr)
	{
        prev = slow;
        slow = slow->next;
    }

    // make next of prev node null
    prev->next = nullptr;

    // return mid node
    return slow;
}

// Function to rearrange given linked list in specific way
void rearrange(struct Node* head)
{
    // base case
    if (head == nullptr)
        return;

    // find second half of linked list
    struct Node* mid = findMiddle(head);

    // reverse the second half
    reverse(&mid);

    // merge first and second half
    ShuffleMerge(head, mid);
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(&head, keys[i]);

    rearrange(head);

    printList(head);

    return 0;
}
