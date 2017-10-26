class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return nullptr;
        int gap = 1;
        while (gap<n)
        {
            for (int i = 0; i+gap < n; i += 2*gap) lists[i] = merge(lists[i], lists[i+gap]);
            gap*=2;
        }
        return lists[0];
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode* ans = nullptr, **p = &ans;
        while(l && r) {
            if (l->val <= r->val) {
                *p = l; p = &l->next;
                l = l->next;
            } else {
                *p = r; p = &r->next;
                r = r->next;
            }
        }
        *p = l ? l : r;
        return ans;
    }
};
