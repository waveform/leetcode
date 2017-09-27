class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> lut{{')','('}, {'}','{'}, {']','['}};
        stack<char> st;
        for (auto c:s) {
            if (lut.count(c)) {
                if (st.empty() || st.top()!=lut[c]) return false;
                else st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
