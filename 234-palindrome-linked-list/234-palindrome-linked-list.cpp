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
    ListNode* reverseLinkedList(ListNode* root){
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = root;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


bool isPalindrome(ListNode* root) {
    if (!root)
        return true;

    ListNode* slow = root;
    ListNode* fast = root;
    ListNode* prev = root;
    ListNode* curr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* curr1 = root;
    ListNode* curr2 = NULL;

    //If fast pointer is not null, It means the length of Linked list is odd
    if (fast) {
        curr = reverseLinkedList(slow->next);
        slow->next = curr;
    }
    else{
        curr = reverseLinkedList(slow);
        prev->next = curr;
    }

    curr2 = curr;
    while (curr2) {
        if (curr1->val != curr2->val)
            return false;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;
}
};