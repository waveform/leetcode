class Solution {
public:
vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans(2);
    int n = nums.size();
    long long t = target, m = 0;
    unordered_map<int, int> lut;
    auto iter = lut.begin();
    for (int i = 0; i < n; i++) {
        m = t - nums[i];
        if (m < INT_MIN || m > INT_MAX) {
            lut[nums[i]] = i;
            continue;
        }
        if (iter == lut.end()) continue;
        auto iter = lut.find(m);
        if (iter == lut.end()) {
            lut[nums[i]] = i;
            continue;
        }
        ans[0] = iter->second;
        ans[1] = i;
        break;
    }
    return ans;
}
};
