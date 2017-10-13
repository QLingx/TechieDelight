#include <stdio.h>

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
    struct Node* curr = head;
    while (curr) 
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("nullptr");
}

// main function
int main()
{
    struct Node e = { 5, NULL }; //last node
	struct Node d = { 4, &e };
    struct Node c = { 3, &d };
    struct Node b = { 2, &c };
    struct Node a = { 1, &b };	//first node

    struct Node* head = &a;

    printList(head);

    return 0;
}