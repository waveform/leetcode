class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1) return head;
        ListNode **p = &head;
        while(1) {
            ListNode *q = *p;
            for (int i=1; i<k && q; i++) q = q->next;    
            if (!q) break;
            ListNode *t = nullptr, **np = &(*p)->next;
            while(*p != q) {
                t = *p;
                *p = (*p)->next;
                t->next = q->next;
                q->next = t;
            }
            p = np;
        }
        return head;
    }
};
