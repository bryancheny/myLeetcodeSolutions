class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        vector<vector<vector<string>>> dp;
        dp.push_back({{s.substr(0,1)}});
        for (int i = 1; i < s.length(); i++) {
            dp.push_back(dp[i-1]);
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j].push_back(s.substr(i,1));
            }
            for (int j = i - 1; j >= 0; j--) {
                int left = j, right = i;
                while (s[left] == s[right] && left < right) {
                    left++;
                    right--;
                }
                if (left >= right) {
                    int siz = dp.back().size();
                    if (j == 0) {
                        dp.back().push_back({s.substr(0,i+1)});
                    }
                    else {
                        dp.back().insert(dp.back().end(),dp[j-1].begin(),dp[j-1].end());
                        for (int k = siz; k < dp.back().size(); k++) {
                            dp.back()[k].push_back(s.substr(j,i-j+1));
                        }
                    }
                }
            }
        }
        return dp.back();
    }
};
