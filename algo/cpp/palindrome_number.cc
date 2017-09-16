class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long long t = x, p = 0;
        while(t) {
            int m = t%10;
            t/=10;
            p*=10;
            p+=m;
        }
        return x==p;
    }
};
