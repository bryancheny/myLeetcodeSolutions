class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto &i:nums) s.insert(i);
        int res = 0;
        while (!s.empty()) {
            int curr = 1;
            int start = *s.begin();
            s.erase(start);
            for (int i = start + 1; s.find(i) != s.end(); i++) {
                curr ++;
                s.erase(i);
            }
            for (int j = start - 1; s.find(j) != s.end(); j--) {
                curr ++;
                s.erase(j);
            }
            res = max(res,curr);
        }
        return res;
    }
};
