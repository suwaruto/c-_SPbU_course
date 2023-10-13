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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int overflow = 0;
        while (true)
        {
            if (l1 != NULL)
                cur->val += l1->val;
            if (l2 != NULL)
                cur->val += l2->val;
            cur->val += overflow;
            if (cur->val > 9)
            {
                cur->val -= 10;
                overflow = 1;
            }
            else
                overflow = 0;
            l1 = l1 != NULL ? l1->next : l1;
            l2 = l2 != NULL ? l2->next : l2;
            if (l1 != NULL || l2 != NULL || overflow > 0)
                cur = cur->next = new ListNode();
            else
                break; 
        }
        return head;
    }
};
