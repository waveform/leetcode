class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0].push_back("");
        if (n>0) dp[1].push_back("()");
        for (int i=2;i<=n;i++) {
            int s = 0, t = 0;
            for (int j=0;j<i;j++) s += dp[j].size() * dp[i-1-j].size();
            dp[i].resize(s);
            for (int j=0;j<i;j++) {
                for (auto &inner : dp[j]) {
                    for (auto &outer : dp[i-1-j]) {
                        dp[i][t++] = "(" + inner + ")" + outer;
                    }
                }
            }
        }
        return dp[n];
    }
};
