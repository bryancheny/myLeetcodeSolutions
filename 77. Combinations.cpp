struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (dp.find({n,k}) != dp.end()) return dp[{n,k}];
        if (k > n || k == 0 || n == 0) return {}; 
        if (k == 1) {
            vector<vector<int>> res;
            for (int i = 1; i <= n; i++) {
                res.push_back({i});
            }
            return res;
        }
        vector<vector<int>> selected = combine(n-1,k-1);
        vector<vector<int>> notSelected = combine(n-1,k);
        for (int i = 0; i < selected.size(); i++) {
            selected[i].push_back(n);
        }
        selected.insert(selected.end(),notSelected.begin(),notSelected.end());
        dp[{n,k}] = selected;
        return selected;
    }
private: 
    unordered_map<pair<int,int>,vector<vector<int>>,hash_pair> dp;
};
