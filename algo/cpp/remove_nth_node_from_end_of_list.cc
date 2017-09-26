class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** p = &head;
        ListNode* h = *p;
        while(n--) h = h->next;
        while(h) {
            h = h->next;
            p = &(*p)->next;
        }
        *p = (*p)->next;
        return head;
    }
};
