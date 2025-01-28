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
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;  // prev will point to the node before the pair we want to swap
        
        // Traverse the list in pairs
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            // Swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev to the next pair
            prev = first;
        }
        
        return dummy->next;  // Return the new head of the list
    }
};
