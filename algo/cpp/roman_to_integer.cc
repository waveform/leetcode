class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> lut{
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
        };
        int ans = 0, n = s.size();
        for (int i=0;i<n;i++) {
            if (i+1<n && lut[s[i]]<lut[s[i+1]]) ans -= lut[s[i]];
            else ans += lut[s[i]];
        }
        return ans;
    }
};
