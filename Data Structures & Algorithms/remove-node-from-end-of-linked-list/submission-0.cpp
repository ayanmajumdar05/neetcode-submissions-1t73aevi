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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);

        ListNode* left = dummy;
        ListNode* right = head;

        while(n>0 && right!=NULL) // shift right pointer to proper position
        {
            right = right->next;
            n -= 1;
        }

        while(right != NULL) // traverse till right is at end and left is at proper position
        {
            left = left->next;
            right = right->next;
        }

        //deleting next node from left
        left->next = left->next->next;
        return dummy->next;

    }
};
