class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify list manipulation
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;  // To store carry during addition

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with carry from the previous step
            
            // Add the value from l1 if it's available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // Move to the next node in l1
            }
            
            // Add the value from l2 if it's available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // Move to the next node in l2
            }

            // Update carry for the next iteration
            carry = sum / 10;
            
            // Create a new node for the current sum's ones place (sum % 10)
            current->next = new ListNode(sum % 10);
            current = current->next;  // Move to the next node in the result list
        }

        // Return the next node of dummyHead which points to the actual result
        return dummyHead->next;
    }
};
