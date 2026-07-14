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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto& l : lists) {
            minHeap.push(l);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!minHeap.empty()) {
            if (minHeap.top()->next) {
                minHeap.push(minHeap.top()->next);
            }
            curr->next = minHeap.top();
            minHeap.pop();
            curr = curr->next;
        }

        return dummy->next;
    }
};
