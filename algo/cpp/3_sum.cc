class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0;i<n-2;i++) {
            if (i>0 && nums[i-1]==nums[i]) continue;
            if (nums[i]+nums[i+1]+nums[i+2] > 0) break;
            if (nums[i]+nums[n-2]+nums[n-1] < 0) continue;
            int l = i+1, r = n-1, t = -nums[i];
            while(l<r) {
                int t = nums[l]+nums[r];
                if (t+nums[i]<0) l++;
                else if (t+nums[i]>0) r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    do { l++; } while(nums[l-1]==nums[l]);
                    do { r--; } while(nums[r+1]==nums[r]);
                }
            }
        }
        return ans;
    }
};
