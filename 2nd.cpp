//Doubly link list

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    cout<< endl;
    return len;
}

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //if it is 1st position
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt=1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    //for any mid position
    Node* nodeoinsert = new Node(40);
    
}

int main(){

    Node* node1 = new Node(10); 
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtHead(head, 20);  
    print(head);

    insertAtTail(tail , 30);
    print(head);

    insertAtPosition(head,tail,2,40);

    cout<<getLength(head)<<endl;
    return 0;
}