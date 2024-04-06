#include<iostream>
using namespace std;

class Node{
    public:

    int data = 0;
    Node* next = NULL;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(Node* &head,Node* &tail ,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
    }else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

int getLength(Node* head){
    Node* temp = head;
    int length = 0;
    while (temp!= NULL)
    {
       temp = temp->next;
        length++;
    }
    return length;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int len = getLength(head);
    if(position == 1) {
        insertAtHead(head,tail, data);
        return;
    }
    if(position > len){
        insertAtTail(head, tail, data);
        return;
    }else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* current = head;

        while(position != 1){
            position--;
            prev = current;
            current = current->next;
        }

        newNode->next = current;
        prev->next = newNode;
    }

}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->" ;
        temp = temp->next;
    }
}

void deletion(Node* &head, Node* &tail, int position){
    int len = getLength(head);

    //No Node is present
    if(head == NULL){
        cout << "No Node is present Please Insert a Node first" << endl; 
    }
    //Delete if tail and head pointing to the same location
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    //Delete from head
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp = NULL;
        delete temp;
    }
    //Deletion form tail
    if(position == len){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        temp = tail;
    }else{
        //Delete form middle
        int pos = position;
        Node* prev = NULL;
        Node* current = head;
        while (pos != 1)
        {
            pos--;
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
        

    }
    
    
}

int main() {

    Node* first = new Node(1);
    Node* Second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* tail = fourth;
    Node* head = first;
    first->next = Second;
    Second->next = third;
    third->next = fourth;
    // insertAtHead(head,tail ,1000);
    // insertAtTail(head, tail, 2000);
    // insertAtPosition(head, tail, 400, 3);
     print(head);
    cout << endl;
    deletion(head, tail, 4);
    cout << endl;
    print(head);
    cout << endl;

cout << "The Length of the Linked List is:" << getLength(head) << endl;

   return 0;
}