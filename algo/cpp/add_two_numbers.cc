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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr, **p = &ans;
        int c = 0;
        while(l1 || l2) {
            if (l1) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                c += l2->val;
                l2 = l2->next;
            }
            *p = new ListNode(c>9?c-10:c);
            p = &(*p)->next;
            c = c>9 ? 1 : 0;
        }
        if (c) {
            *p = new ListNode(c);
        }
        return ans;
    }
}
