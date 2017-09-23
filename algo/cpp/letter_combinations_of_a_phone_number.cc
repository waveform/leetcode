vector<string> lut{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.find_first_of("01")!=string::npos) return ans;
        string word;
        helper(ans, word, digits);
        return ans;
    }
    void helper(vector<string>& ans, string& word, string& digits) {
        int i = word.size();
        if (i==digits.size() && i) { ans.push_back(word); return; }
        word.push_back(' ');
        for (auto c:lut[digits[i]-'0']) {
            word.back() = c;
            helper(ans, word, digits);
        }
        word.pop_back();
    }
};
