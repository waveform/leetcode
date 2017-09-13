class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows>=n || numRows==1) return s;
        string ans;
        for (int i=0;i<numRows;i++) {
            int j = i, t = (numRows - 1 - i) * 2;
            while(j<n) {
                if (t) {
                    ans.push_back(s[j]);
                    j += t;
                }
                t = (numRows - 1) * 2 - t;
            }
        }
        return ans;
    }
};
