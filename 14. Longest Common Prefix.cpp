class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        while (true) {
            int curr = ans.length();
            if (strs[0].length() <= curr) return ans;
            for (int i = 1; i < strs.size() ; i++) {
                if (strs[i].length() <= curr) return ans;
                if (strs[i][curr] != strs[i-1][curr]) return ans;
            }
            ans += strs[0][curr];
        }
        return ans;
    }
};
