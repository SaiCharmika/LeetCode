class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make it a circular list
        tail->next = head;

        // Step 3: Find the new head (after (length - k % length) steps)
        int stepsToNewHead = length - (k % length);
        for (int i = 0; i < stepsToNewHead; i++) {
            tail = tail->next;
        }

        // Step 4: Break the circular list
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};
