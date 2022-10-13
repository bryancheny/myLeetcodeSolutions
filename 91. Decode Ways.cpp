class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1);
        dp[0] = 1; dp[1] = 1;
        if (s[0] == '0') return 0;
        for (int i = 2; i < dp.size(); i++) {
            if (s[i-1] == '0') {
                if (s[i-2] == '1' || s[i-2] == '2') dp[i] = dp[i - 2];
                else return 0;
            }
            else {
                dp[i] = dp[i-1];
                if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) 
                dp[i] += dp[i-2];
            }
        }
        return dp.back();
    }
};
