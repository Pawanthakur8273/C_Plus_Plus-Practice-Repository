// Function to find the middle node of a linked list
Node* mid(Node* head) {
    // Create a temporary pointer to traverse the linked list
    Node* temp = head;

    // Check if the linked list is empty
    if (temp == NULL) {
        // If the linked list is empty, print a message and return NULL
        cout << "Please insert a Node to find mid" << endl;
    } else {
        // Initialize two pointers, slow and fast, both pointing to the head of the linked list
        Node* slow = head;
        Node* fast = head;

        // Traverse the linked list until the fast pointer reaches the end
        while (fast != NULL) {
            // Move the fast pointer two nodes ahead
            fast = fast->next;
            // If the fast pointer is still not at the end, move it one more node ahead and move the slow pointer one node ahead
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        // When the fast pointer reaches the end, the slow pointer will be at the middle node of the linked list
        return slow;
    }
}
