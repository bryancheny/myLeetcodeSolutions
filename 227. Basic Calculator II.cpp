class Solution {
public:
    int calculate(string s) {
        long res = 0;
        bool isAdd = true;
        long cache = 0;
        long curr = 0;
        enum operation {multiply, divide, neither};
        operation lastOperation = neither;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                curr = 10 * curr + (s[i] - '0');
                if (i + 1 < s.length() && isdigit(s[i+1])) continue;
                if (lastOperation == neither) cache = curr;
                else if (lastOperation == multiply) cache *= curr;
                else cache /= curr;
                curr = 0;
            }
            else if (s[i] == '+') {
                if (isAdd) res += cache;
                else res -= cache;
                isAdd = true;
                lastOperation = neither;
            }
            else if (s[i] == '-') {
                if (isAdd) res += cache;
                else res -= cache;
                isAdd = false;
                lastOperation = neither;
            }
            else if (s[i] == '*') {
                lastOperation = multiply;
            }
            else if (s[i] == '/') {
                lastOperation = divide;
            }
            
        }
        if (isAdd) res += cache;
        else res -= cache;
        return res;
    }
};
