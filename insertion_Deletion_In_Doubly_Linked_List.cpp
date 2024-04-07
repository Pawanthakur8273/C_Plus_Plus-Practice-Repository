#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    // Constructor with data initialization
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to get the length of the doubly linked list
int getLen(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to insert a node at the head of the doubly linked list
void insertAtHead(int data, Node* &head, Node* &tail) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert a node at the tail of the doubly linked list
void insertAtTail(int data, Node* &head, Node* &tail) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert a node at a specified position in the doubly linked list
void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
    int len = getLen(head);
    int pos = position;
    if (pos == 1) {
        insertAtHead(data, head, tail);
    }
    else if (pos >= len) {
        insertAtTail(data, head, tail);
    }
    else {
        Node* CurrentNode = head;
        Node* PrevNode = NULL;
        while (pos != 1) {
            pos--;
            PrevNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }
        Node* newNode = new Node(data);
        PrevNode->next = newNode;
        newNode->prev = PrevNode;
        newNode->next = CurrentNode;
        CurrentNode->prev = newNode;
    }
}

// Function to delete a node from the doubly linked list at a specified position
void deletion(Node* &head, Node* &tail, int position) {
    int len = getLen(head);
    int pos = position;
    if (head == NULL) {
        cout << "Nothing to delete. Please insert a node." << endl;
    }
    else if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }
    else if (pos == len) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        delete temp;
    }
    else {
        Node* PrevNode = NULL;
        Node* CurrentNode = head;
        while (pos != 1) {
            pos--;
            PrevNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }
        Node* NextNode = CurrentNode->next;
        PrevNode->next = NextNode;
        if (NextNode != NULL)
            NextNode->prev = PrevNode;
        CurrentNode->next = NULL;
        CurrentNode->prev = NULL;
        delete CurrentNode;
    }
}

// Function to print the doubly linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    // Inserting nodes at different positions
    insertAtPosition(10, 1, head, tail);
    insertAtPosition(20, 2, head, tail);
    insertAtPosition(30, 3, head, tail);
    
    // Deleting a node from the list
    deletion(head, tail, 1);
    
    // Printing the modified list
    print(head);

    return 0;
}
