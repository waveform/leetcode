class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.size(), pl = p.size();
        return recur(s, p, sl-1, pl-1);
    }
    bool recur(string& s, string& p, int si, int pi) {
        if (si == -1 && pi == -1) return true;
        if (pi == -1) return false;
        if (si == -1) {
            if (p[pi] == '*') return recur(s, p, si, pi-2);
            else return false;
        }
        if (p[pi] == '*') {
            --pi;
            int se = -1;
            if (p[pi] != '.') {
                se = si;
                while(se>=0 && (s[se]==p[pi])) --se; 
            }
            for (int i=se; i<=si; i++) if (recur(s, p, i, pi-1)) return true;
        } else {
            if (p[pi]!='.' && p[pi]!=s[si]) return false;
            return recur(s, p, si-1, pi-1);
        }
        return false;
    }
};
