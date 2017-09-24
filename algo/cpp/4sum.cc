class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0;i<n-3;i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target) continue;
            for (int j=i+1;j<n-2;j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if (nums[i]+nums[j]+nums[n-2]+nums[n-1] < target) continue;
                int t = target - nums[i] - nums[j], l = j+1, r = n-1;
                while(l<r) {
                    if (nums[l]+nums[r]>t) r--;
                    else if (nums[l]+nums[r]<t) l++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do { r--; } while(l<r && nums[r]==nums[r+1]);
                        do { l++; } while(l<r && nums[l]==nums[l-1]);
                    }
                }
            }
        }
        return ans;
    }
};
