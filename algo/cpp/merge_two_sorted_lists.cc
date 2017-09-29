class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, **p = &head;
        while(l1 && l2) {
            if (l1->val > l2->val) {
                *p = l2;
                l2 = l2->next;
            } else {
                *p = l1;
                l1 = l1->next;
            }
            p = &(*p)->next;
        }
        *p = l1 ? l1 : l2;
        return head;
    }
};
