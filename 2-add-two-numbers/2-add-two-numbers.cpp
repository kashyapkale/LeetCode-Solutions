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

int getData(ListNode* curr_node){
    if (!curr_node)
        return 0;

    return curr_node->val;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2)
        return NULL;

    ListNode* ans = new ListNode(-1);
    ListNode* retAns = ans;
    int carry = 0;

    while (l1 || l2) {
        int currSum = getData(l1) + getData(l2) + carry;
        ans->next = new ListNode(currSum % 10);
        carry = currSum / 10;
        ans = ans->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if(carry){
        ans->next = new ListNode(carry);
    }
        
    return retAns->next;
}
};