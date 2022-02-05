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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > minHeap;

    for (auto it:lists) {
        if (it)
            minHeap.push({ it->val, it });
    }

    ListNode* head = new ListNode(-1);
    ListNode* curr = head;

    while (!minHeap.empty()) {
        pair<int, ListNode*> temp = minHeap.top();
        curr->next = temp.second;
        minHeap.pop();
        if (temp.second->next)
            minHeap.push({ temp.second->next->val, temp.second->next });
        curr = curr->next;
    }
    curr->next = NULL;

    return head->next;
}
};