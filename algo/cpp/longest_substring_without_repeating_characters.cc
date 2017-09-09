class Solution {
public:
    // solution #1: O(n)
    /*
    int lengthOfLongestSubstring(string s) {
        int lut[256] = {0};
        int b = 0, e = 0, ans = 0, n = s.size();
        while(1) {
            while(e<n && !lut[s[e]]) { lut[s[e++]] = 1; }
            ans = max(ans, e - b);
            if (e>=n) break;
            while(lut[s[e]]) lut[s[b++]] = 0;
        }
        return ans;
    }
    */

    // solution #2: O(n)
    int lengthOfLongestSubstring(string s) {
        vector<int> lut(256, -1);
        int ans = 0, start = -1, n = s.size();
        for (int i=0; i<n; i++) {
            start = max(start, lut[s[i]]);
            lut[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};
