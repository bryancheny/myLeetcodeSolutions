class Solution {
public:
    int minDistance(string word1, string word2) {
        // iterate word1 and word2 through iterators left and left2, if start of both words don't match, delete one char from each word and recursively find the answer 
        dp = vector<vector<int>> (word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return dfs(word1, word2, 0, 0);
    }
    
    int dfs (string &word1, string &word2, int left, int left2) {
        if (dp[left][left2] != -1) return dp[left][left2];
        if (left == word1.length()) return word2.length() - left2;
        if (left2 == word2.length()) return word1.length() - left;                                                       
        if (word1[left] == word2[left2]) {
            dp[left][left2] = dfs(word1, word2, left + 1, left2 + 1);
            return dp[left][left2];
        }
        else {
            
            dp[left][left2] = min(dfs(word1, word2, left + 1, left2) + 1, dfs(word1, word2, left, left2 + 1) + 1);
            return dp[left][left2];
        }
    }
    private:
    vector<vector<int>> dp;
};
