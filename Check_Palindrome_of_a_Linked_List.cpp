/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {)
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Function to reverse a singly-linked list
    ListNode* reverse(ListNode* head) {
        // Initialize pointers
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* current = head;
        // Iterate through the list, reversing pointers
        while (current != NULL) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev; // Return the new head of the reversed list
    }

    // Function to find the middle node of a singly-linked list
    ListNode* mid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // Traverse the list using two pointers, one moving twice as fast as the other
        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow; // Return the middle node
    }

    // Function to check if two linked lists are equal
    bool isValid(ListNode* head, ListNode* head2) {
        while (head2 != NULL) {
            // If values are not equal, the lists are not palindromic
            if (head->val != head2->val) {
                return false;
            } else {
                head = head->next;
                head2 = head2->next;
            }
        }
        return true; // If all values are equal, lists are palindromic
    }

    // Function to check if a singly-linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        ListNode* midi = mid(head); // Find the middle node of the list
        ListNode* head2 = midi->next; // Split the list into two parts from the middle
        midi->next =  NULL; // Disconnect the first half from the second half
        head2 = reverse(head2); // Reverse the second half of the list
        return isValid(head, head2); // Check if the two halves are equal
    }
};
