#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the node value, list index and the node itself
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Push the head of each list into the heap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }
        
        // Dummy node to form the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Merge the lists using the min-heap
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            current->next = node;
            current = current->next;
            
            // If there's a next node in the same list, push it to the heap
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return dummy->next;  // Return the merged list, starting from the first real node
    }
};
