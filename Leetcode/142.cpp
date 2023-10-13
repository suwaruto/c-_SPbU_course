/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *tort = head, *hare = head;
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return NULL;
        while (hare != NULL && hare->next != NULL && tort != NULL)
        {
            tort = tort->next;
            hare = hare->next->next;
            if (tort == hare)
                break;
        }
        if (hare == NULL || hare->next == NULL || tort == NULL)
            return NULL;
        hare = head;
        while (hare != tort)
        {
            hare = hare->next;
            tort = tort->next;
        }
        return tort;
    }
};
