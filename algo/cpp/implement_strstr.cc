class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        return find(haystack, needle);
    }
private:
vector<int> suffix(const string& pattern) {
    int m = pattern.size();
    vector<int> suff(m);
    suff[m-1] = m;
    for (int i= m - 2; i >= 0; i--) {
        int j = i;
        while(j >= 0 && pattern[j]==pattern[m-1-i+j]) j--;
        suff[i] = i - j;
    }
    return suff;
}
vector<int> pre_process_good_suffix(const string& pattern) {
    vector<int> suff = suffix(pattern);
    int m = pattern.size();
    vector<int> good_suffix(m, m); // case #3
    int j = 0;
    for (int i = m-1; i>=0; i--) { // case #2
        if (suff[i] != i+1) continue;
        for (; j < m - 1 - i; j++) {
            if (good_suffix[j] != m) continue;
            good_suffix[j] = m - 1 - i;
        }
    }
    for (int i = 0; i < m-1; i++) { // case #1
        good_suffix[m - 1 - suff[i]] = m - 1 - i;
    }
    return good_suffix;
}
vector<int> pre_process_bad_char(const string& pattern) {
    int m = pattern.size();
    vector<int> bad_char(256, m);
    for (int i=0;i<m-1;i++) bad_char[pattern[i]] = m - 1 - i;
    return bad_char;
}
int find(const string& text, const string& pattern) {
    vector<int> bad_char = pre_process_bad_char(pattern);
    vector<int> good_suffix = pre_process_good_suffix(pattern);
    int i = 0, j = 0, n = text.size(), m = pattern.size();
    while(j <= n - m) {
        for (i = m - 1; i >= 0 && pattern[i] == text[i+j]; i--);
        if (i < 0) return j;
        j += max(bad_char[text[i+j]] - m + 1 + i, good_suffix[i]);
    }
    return -1;
}
};
