class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(),copy.end());
            hash[copy].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (const auto &it:hash) {
            res.push_back(it.second);
        }
        return res;
    }
};
