class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) return "0";
        stack<char> s; // stack of increasing digits
        int erased = 0;
        for (int i = 0; i < num.length(); i++) {
            if (s.empty() || s.top() <= num[i] || erased == k) {
                s.push(num[i]);
            }
            else {
                while(erased < k && !s.empty() && s.top() > num[i]) {
                    s.pop();
                    erased++;
                }
                s.push(num[i]);
            }
        }
        if (erased < k) {
            for (int i = 0; i < (k - erased); i++) {
                s.pop(); // Erase last digits
            }
        }
        string res(num.length() - k, 'x');
        int stacksize = s.size();
        for (int i = 0; i < stacksize; i++) {
            res[stacksize - i - 1] = s.top();
            s.pop();
        }
        int start = 0;
        while (res[start] == '0' && start!= res.length() - 1) {
            start++;
        }
        return res.substr(start);
    }
};
