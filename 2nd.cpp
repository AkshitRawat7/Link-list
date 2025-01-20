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

    ~Node(){
        int val = this->data;

        if(next != NULL){
            delete next;
            next=NULL;
        }
        cout<< "memory free for node with data " << data <<endl;
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

void insertAtHead(Node* &tail,Node* &head , int d){

    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &tail,Node* &head,int d){

    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node* temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}

// Delete a node at a given position
void deleteNode(int position, Node* &head,Node* &tail) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // To delete the first node
    if (position == 1) {
        Node* temp = head; // Store the current head node in 'temp'
        temp->next->prev= NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // To delete a node at any other position
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    // Traverse to the node just before the one to delete
    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    // If the position is invalid (greater than the length of the list)
    if (curr == NULL) {
        cout << "Invalid position! No node to delete." << endl;
        return;
    }
    
    //updating the tail when we delete the tail
    if(curr->next == NULL)
    {
        tail = prev; // update previous node as tail
    }

    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //if it is 1st position
    if(position == 1){
        insertAtHead(tail,head,d);
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
        insertAtTail(tail,head,d);
        return;
    }

    //for any mid position
    Node* nodetoinsert = new Node(40);

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    nodetoinsert->prev = temp;
    temp->next = nodetoinsert;
}

int main(){

    Node* node1 = new Node(10); 
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtHead(tail,head,20);  
    print(head);

    insertAtTail(tail,head,30);
    print(head);

    insertAtPosition(head,tail,2,40);
    print(head);

    cout<< "Head "<< head->data <<endl;
    cout<< "Tail "<< tail->data <<endl;

    deleteNode(4,head,tail);
    print(head);

    cout<< "Head "<< head->data <<endl;
    cout<< "Tail "<< tail->data <<endl;

    cout<<getLength(head)<<endl;

    return 0;
}