ass Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        long long t = target, diff = LONG_MAX, ans = 0;
        for (int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while (l<r) {
                long long s = 0ll + nums[i] + nums[l] + nums[r];
                if (s==t) return (int)t;
                if (labs(s-t) < diff) {
                    diff = labs(s-t);
                    ans = s;
                }
                if (s>t) r--;
                else l++;
            }
        }
        return (int)ans;
    }
};
