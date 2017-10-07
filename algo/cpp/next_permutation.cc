class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1;
        if (!n) return;
        while(i>0 && nums[i-1]>=nums[i]) i--;
        reverse(nums.begin()+i, nums.end());
        if (i>0) {
            int idx = upper_bound(nums.begin()+i, nums.end(), nums[i-1]) - nums.begin();
            swap(nums[idx], nums[i-1]);
        }
    }
};
