/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Edge case: if k is 1 or list is empty, return the head as is
        if (k == 1 || !head) return head;
        
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify head handling
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;  // Points to the node before the current group
        ListNode* curr = head;  // Pointer to traverse the list
        
        // Function to reverse k nodes
        auto reverse = [](ListNode* start, int k) {
            ListNode* prev = nullptr;
            ListNode* curr = start;
            ListNode* next = nullptr;
            while (k--) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;  // New head after reversal
        };
        
        while (curr) {
            // Check if there are enough nodes to reverse (k nodes left)
            ListNode* groupEnd = curr;
            for (int i = 1; i < k && groupEnd; i++) {
                groupEnd = groupEnd->next;
            }
            
            // If there are enough nodes for a group
            if (groupEnd) {
                ListNode* nextGroupStart = groupEnd->next;
                
                // Reverse the k nodes
                ListNode* newGroupHead = reverse(curr, k);
                
                // Connect the previous part with the reversed group
                prevGroupEnd->next = newGroupHead;
                curr->next = nextGroupStart;
                
                // Move prevGroupEnd and curr to the next group
                prevGroupEnd = curr;
                curr = nextGroupStart;
            } else {
                // Not enough nodes to reverse, break out of the loop
                break;
            }
        }
        
        return dummy->next;  // Return the new head of the list
    }
};
