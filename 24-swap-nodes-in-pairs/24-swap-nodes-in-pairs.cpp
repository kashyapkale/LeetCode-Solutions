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
    ListNode* curr = head;
    if(!curr)
        return NULL;
    if (!curr->next)
        return head;
    ListNode* AdjCurr = head->next;

    while (curr && curr->next) {
        swap(curr->val, AdjCurr->val);
        curr = curr->next->next;
        if(curr && curr->next)
            AdjCurr = curr->next;
    }

    return head;
}
};