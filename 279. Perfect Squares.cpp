class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n+1,0);
        int curr;
       for (int i = 1; i < n + 1; i++) {
           curr = INT_MAX;
           for (int j = 1; j <= pow(i,1.0/2); j++) {
                curr = min(curr,dp[i - pow(j,2)] + 1);   
           }
           dp[i] = curr;
       }
        return dp[n];
    }
};
