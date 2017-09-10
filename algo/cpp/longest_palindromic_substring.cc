class Solution {
public:
    // DP: O(n^2)
    /*
    string longestPalindrome(string s) {
        string ans;
        vector<vector<int>> dp(2);
        int prev=0, curr=1, n = s.size();
        for (int i=0;i<n;i++) {
            swap(curr, prev);
            dp[curr].clear();
            for (int l : dp[prev]) {
                if (i-l-1<0 || s[i-l-1]!=s[i]) continue;
                dp[curr].push_back(l+2);
            }
            if (i>0 && s[i]==s[i-1]) dp[curr].push_back(2);
            dp[curr].push_back(1);
            if (ans.size()<dp[curr][0]) {
                ans = s.substr(i-dp[curr][0]+1, dp[curr][0]);
            }
        }
        return ans;
    }
    */
    // Manacher
    string longestPalindrome(string s) {
        int n = s.size();
        // build string from "CAAB" to "^#C#A#A#B#$"
        string st(n*2+1+2, '#');
        vector<int> len(n*2+1+2);
        st.front() = '^';
        st.back() = '$';
        for (int i=0;i<n;i++) st[2*i+2] = s[i];
        // [i, right) half open half close iternval
        int right = 0, mid = 0, longest_len = 0, longest_mid = 0;
        for (int i=1; i<st.size()-1; i++) {
            if (right > i) len[i] = min(right-i, len[2*mid-i]);
            else len[i] = 1;
            while (st[i+len[i]] == st[i-len[i]]) len[i]++;
            if (len[i]+i > right) {
                right = len[i]+i;
                mid = i;
            }
            if (len[i] > longest_len) {
                longest_len = len[i];
                longest_mid = i;
            }
        }
        // convert coord from st to t
        int start = (longest_mid - longest_len + 1 - 1) / 2;
        int length = longest_len - 1;
        return s.substr(start, length);
    }
};
