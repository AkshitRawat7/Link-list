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

// Insert at the head
void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* newNode = new Node(d);

    if (!head) { // If the list is empty
        head = newNode;
        tail = newNode;
        newNode->next = newNode; // Make it circular
    } else {
        newNode->next = head;
        tail->next = newNode; // Update tail to point to the new head
        head = newNode; // Update head to the new node
    }
}

// Insert at the tail
void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* newNode = new Node(d);

    if (!head) { // If the list is empty
        head = newNode;
        tail = newNode;
        newNode->next = newNode; // Make it circular
    } else {
        tail->next = newNode; // Link the old tail to the new node
        newNode->next = head; // Make it circular
        tail = newNode; // Update tail to the new node
    }
}

// Delete a node at a given position
void deleteNode(Node*& head, Node*& tail, int position) {
    if (!head) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // If deleting the first node
    if (position == 1) {
        Node* temp = head;

        if (head == tail) { // If only one node exists
            head = NULL;
            tail = NULL;
        } else {
            head = head->next; // Update head to the next node
            tail->next = head; // Update tail to point to the new head
        }

        temp->next = NULL; // Break the link
        delete temp;       // Free memory
        return;
    }

    // For other positions
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while (cnt < position && curr != tail) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (cnt != position || !curr) {
        cout << "Invalid position! No node to delete." << endl;
        return;
    }

    // Update tail if the last node is being deleted
    if (curr == tail) {
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

// Find the middle element of the list
Node* middleElement(Node* head) {
    if (!head || head->next == head) { // For empty or single-node list
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Print the circular linked list
void print(Node* head, Node* tail) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Check if the list is circular
bool isCircular(Node*& head) {
    if (!head) {
        return false; // An empty list is not circular
    }

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head); // Returns true if the list loops back to head
}

// Main function
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes at the tail
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    print(head, tail);

    // Insert at the head
    insertAtHead(head, tail, 5);
    print(head, tail);

    // Insert at position
    insertAtTail(head, tail, 40);
    print(head, tail);

    // Find the middle element
    Node* middle = middleElement(head);
    if (middle) {
        cout << "Middle element: " << middle->data << endl;
    }

    // Delete all nodes
    deleteNode(head, tail, 1);
    // deleteNode(head, tail, 1);
    // deleteNode(head, tail, 1);
    // deleteNode(head, tail, 1);
    deleteNode(head, tail, 5);

    if (isCircular(head)) {
        cout << "LL is Circular" << endl;
    } else {
        cout << "LL is NOT Circular" << endl;
    }

    return 0;
}
