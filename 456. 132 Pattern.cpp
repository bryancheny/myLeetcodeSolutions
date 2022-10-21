class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // keep a decreasing stack of intervals
        stack<pair<int,int>> s;
        int l = INT_MAX,r = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (l < nums[i] && nums[i] < r) return true;
            if (nums[i] < l) {
                l = nums[i];
                r = l;
            }
            else if (nums[i] > r) {
                r = nums[i];
                while (!s.empty()) {
                    pair<int,int> curr = s.top();
                    if (r < curr.first) break;
                    if (r > curr.first && r < curr.second) return true;
                    s.pop();
                    r = max(r, curr.second);
                }
                s.push({l,r});
            }
        }
        return false;
    }
};
