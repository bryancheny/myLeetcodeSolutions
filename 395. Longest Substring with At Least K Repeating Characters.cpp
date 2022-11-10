class Solution {
public:
    int helper (string &s, int k, int start, int end) {
        if (end - start + 1 < k) return 0;
        unordered_map<char,int> count;
        for (int i = start; i <= end; i++) {
            count[s[i]]++;
        }
        bool isGood = true;
        for (auto it:count) {
            if (it.second < k) {isGood = false; break;}
        }
        if (isGood) return end - start + 1;
        int res = 0, curr = start;
        for (int i = start; i <= end; i++) {
            if (count[s[i]] < k) {
                res = max(res, helper(s,k,curr,i-1));
                curr = i + 1;
            }
        }
        res = max(res, helper(s,k,curr,end));
        return res;
    }
    int longestSubstring(string s, int k) {
        return helper(s,k,0,s.length()-1);
    }
};
