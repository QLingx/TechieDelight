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

// Recursive function to check if linked list is palindrome or not
bool checkPalindrome(Node*& left, Node* right)
{
    // base case
    if (right == nullptr)
        return true;

    bool res = checkPalindrome(left, right->next) && (left->data == right->data);
    left = left->next;

    return res;
}

// Function to check if linked list is palindrome or not
bool checkPalindrome(Node* head)
{
    return checkPalindrome(head, head);
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 3, 5, 3, 1};
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        push(head, keys[i]);

    if (checkPalindrome(head))
        cout << "Linked list is Palindrome";
    else
        cout << "Linked list is not Palindrome";

    return 0;
}
