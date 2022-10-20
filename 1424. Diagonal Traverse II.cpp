class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<stack<int>> v;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (v.size() <= i + j) v.push_back(stack<int>());
                v[i+j].push(nums[i][j]);
            }
        }
        vector<int> res;
        for (auto &s:v) {
            while (!s.empty()) {
                res.push_back(s.top());
                s.pop();
            }
        }
        return res;
    }
};
