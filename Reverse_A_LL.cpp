#include <iostream>

// Define a Node structure to represent each element in the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize data and next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// Define a LinkedList class to manage the linked list operations
class LinkedList {
private:
    Node* head;     // Pointer to the first node in the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void append(int data) {
        Node* new_node = new Node(data); // Create a new node with given data
        if (head == nullptr) {
            head = new_node; // If the list is empty, make the new node the head
            return;
        }
        // Traverse the list to find the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Append the new node to the end of the list
        current->next = new_node;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;   // Pointer to store the previous node
        Node* current = head;   // Pointer to traverse the list
        Node* next_node = nullptr;  // Pointer to store the next node temporarily

        // Traverse the list and reverse the links
        while (current != nullptr) {
            // Store the next node
            next_node = current->next;
            // Reverse the link of current node
            current->next = prev;
            // Move pointers one position ahead
            prev = current;
            current = next_node;
        }
        // Update the head to point to the last node (new first node)
        head = prev;
    }

    // Function to print the elements of the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Main function to test the LinkedList implementation
int main() {
    // Create a new linked list
    LinkedList list;

    // Append elements to the list
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    // Print the original list
    std::cout << "Original list: ";
    list.printList();

    // Reverse the list
    list.reverse();

    // Print the reversed list
    std::cout << "Reversed list: ";
    list.printList();

    return 0;
}
