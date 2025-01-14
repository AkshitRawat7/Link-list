//Singly link list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;

        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data " << value << endl;
    }
};

// Insert new node at the head
void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert new node at the tail
void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// Delete a node at a given position
void deleteNode(int position, Node* &head ,Node* &tail) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // To delete the first node
    if (position == 1) {
        Node* temp = head; // Store the current head node in 'temp'
        head = head->next; // Move the head pointer to the next node
        temp->next = NULL; // Disconnect the node from the list
        delete temp;       // Free memory
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

    prev->next = curr->next; // Update the previous node's next pointer
    curr->next = NULL;       // Disconnect the node from the list
    delete curr;             // Free memory
}

// Insert at any position in the linked list
void InsertAtPosition(Node*& head, Node*& tail, int position, int d) {
    // Insert at the start
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the node just before the desired position
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at the last position
    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // Creating a node for 'd'
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Print the linked list
void print(Node*  &head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create a new node
    Node* node1 = new Node(10);

    // Head and tail point to the first node
    Node* head = node1;
    Node* tail = node1;

    // Print the initial list
    print(head);

    // Insert nodes at the tail
    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    // Insert a node at position 1
    InsertAtPosition(head, tail, 1, 100);
    print(head);

    cout<< "Head " << head->data <<endl; 
    cout<< "Tail " << tail->data <<endl; 

    // Delete the second node
    deleteNode(4, head , tail);
    print(head);

    cout<< "Head " << head->data <<endl; 
    cout<< "Tail " << tail->data <<endl; 

    return 0;
}
