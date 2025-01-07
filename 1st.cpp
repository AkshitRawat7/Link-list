#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor 
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }
};

//Insert new node at the end 
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp ->next = head;
    head = temp;
}

//insert at any position in LL
void InsertAtPosition(Node* &head,int position, int d){
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }
     
    Node* temp = head;
    int cnt=1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    // creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}



// Insert new node at the end   
void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next=temp;
    tail= tail->next;   
}

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp ->data <<" ";        
        temp = temp -> next;        
    }
    cout<<endl;
}

int main(){
    //creted a new node
    Node* node1 = new Node(10);
    cout<<"Data "<< node1 -> data <<endl;
    cout<<"Next pointer "<< node1 -> next <<endl;

    //head pointed to node
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    InsertAtPosition(head,1,100);
    print(head);

    return 0;
}