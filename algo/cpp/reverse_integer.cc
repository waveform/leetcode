class Solution {
public:
    // handle as string
    /*
    int reverse(int x) {
        string in = to_string(x);
        string minimal = to_string(INT_MIN).substr(1), maximal = to_string(INT_MAX);
        bool negative = false;
        if (in[0]=='-') {
            negative = true;
            in = in.substr(1);
        }
        //reverse(begin(in), end(in));
        //reverse(in.begin(), in.end());
        int l = 0, r = in.size() - 1;
        while(l<r) swap(in[l++], in[r--]);
        if (negative) {
            if (in.size()>=minimal.size() && in > minimal) return 0;
            return -stoi(in);
        } else {
            if (in.size()>=maximal.size() && in > maximal) return 0;
            return stoi(in);
        }
        return 0;
    }
    */
    // handle as number
    int reverse(int x) {
        long long xx = x, tt = 0;
        bool negative =  (xx < 0);
        xx = llabs(xx);
        while (xx) {
            tt*=10;
            tt += xx%10;
            xx /= 10;
        }
        if (negative) {
            tt*=-1;
            if (tt < INT_MIN) return 0;
        } else if (tt > INT_MAX) return 0;
        return tt;
    }
};
