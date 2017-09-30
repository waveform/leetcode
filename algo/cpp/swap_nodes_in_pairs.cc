class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** p = &head;
        while(*p && (*p)->next) {
            ListNode *n = (*p)->next->next;
            (*p)->next->next = *p;
            *p = (*p)->next;
            (*p)->next->next = n;
            p = &(*p)->next->next;
        }
        return head;
    }
};
