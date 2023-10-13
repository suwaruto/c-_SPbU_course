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
    bool hasCycle(ListNode *head) {
        ListNode *tort = head, *hare = head;
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        while (hare != NULL && tort != NULL)
        {
            tort = tort->next;
            hare = hare->next;
            if (hare == NULL)
                return false;
            hare = hare->next;
            if (tort == hare)
                return true;
        }
        return false;
    }
};
