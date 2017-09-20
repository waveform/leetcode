class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = strs[0].size();
        int i = 0;
        for (;i<n;i++) {
            char c = strs[0][i];
            int j = 1;
            for (;j<strs.size();j++) {
                if (i>=strs[j].size() || c!=strs[j][i]) break;
            }
            if (j!=strs.size()) break;
        }
        return strs[0].substr(0,i);
    }
};
