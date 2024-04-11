/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Function to check if a linked list has a cycle
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, both pointing to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Iterate through the linked list until fast pointer reaches the end (NULL)
        while(fast != NULL){
            // Move fast pointer two steps ahead
            fast = fast->next;
            // Check if fast pointer has reached the end (NULL), if not, move it two steps ahead and slow pointer one step ahead
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }

            // If at any point, fast pointer equals slow pointer, it indicates a cycle, return true
            if(fast == slow){
                return true;
            }
        }
        // If fast pointer reaches the end of the list without encountering slow pointer, there is no cycle, return false
        return false;
    }
};
