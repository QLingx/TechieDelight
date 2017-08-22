#include<iostream>

using namespace std;

/*
input 1->2->3->4->5->6->7
output 1 3 2 5 4 7 5

input 9 6 8 3 7
output 6 9 3 8 7
*/

struct Node{
    int data;
    struct Node *next;
};

Node *newNode(int key,Node *ptr){
    Node* node = new Node();
    node->data = key;
    node->next = ptr;

    return node;
}

void push(Node*& headRef,int data){
    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}

void printList(Node* head){
    Node* ptr = head;
    while(ptr){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "null";
}

void rearrange(Node *head){
    if(head == nullptr){
        return;
    }

    Node *ptr = head;
    Node *curr = head->next;

    while(curr){
        if(prev->data > curr->data){
            swap(prev->data,curr->data);
        }

        if(curr->next && curr->next-data > curr->data){
            swap(curr->next->data,curr->data);
        }

        prev = curr->next;

        if(!curr->next){
            break;
        }

        curr = curr->next->next;
    }
}


int main(){
    int keys[] = {1,2,3,4,5,6,7,8,6};
    int n = sizeof(keys) / sizeof(keys[0]);

    Node *head = nullptr;
    for(int i = n-1;i >= 0;i--){
        push(head,keys[i]);
    }

    rearrange(head);

    printList(head);s

    return 0;
}
