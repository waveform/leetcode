class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l<r) {
            int m = l + (r-l)/2;
            if (target<=nums[m]) r = m;
            else l = m + 1;
        }
        return l;
    }
};
