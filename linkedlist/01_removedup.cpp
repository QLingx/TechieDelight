#include<iostream>
#include<unordered_set>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(struct Node* head){
    struct Node* ptr = head;
    while(ptr){
        std::count << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout<< "null";
}

void push(struct Node** headRef,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void RemoveDuplicates(struct Node* head){
    struct Node* previous = nullptr;
    struct Node* current = head;

    std::unordered_set<int> set;

    while(current != nullptr){
        if(set.find(current->data) != set.end()){
            previous->next = current->next;
            delete current;
        }else{
            set.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
}


int main(){
    int keys[] = {5,3,4,2,5,4,1,3};
    int n = sizeof(keys)/sizeof(keys[0]);

    struct Node* head = nullptr;

    for(int i = n-1;i >= 0;i--){
        push(&head,keys[i]);
    }

    RemoveDuplicates(head);

    printList(head);

    return 0;
}


