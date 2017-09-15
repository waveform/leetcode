class Solution {
public:
    int myAtoi(string str) {
        int status = 0, sign = 1; 
        long long ans = 0;
        for (char c:str) {
            switch (status)
            {
                case 0: //init
                    if (isblank(c)) status = 0;
                    else if (isdigit(c)) {
                        ans=c-'0';
                        status = 1;
                    }
                    else if (c=='+' || c=='-') {
                        sign = (c=='+')?sign:-sign;
                        status = 1;
                    }
                    else status = 4;
                    break;
                case 1: //signed
                case 2:
                    if (isdigit(c)) {
                        ans*=10;
                        ans+=c-'0';
                        if (sign*ans > INT_MAX || sign*ans < INT_MIN) status = 4;
                    } else {
                        status = 4;
                    }
                    break;
                case 4:
                    break;
            }
        }
        ans *= sign;
        if (ans<INT_MIN) ans = INT_MIN;
        else if (ans>INT_MAX) ans = INT_MAX;
        return static_cast<int>(ans);
    }
};
