class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        for (int curr = 0; curr <= max; curr++) {
            max = std::max(max, curr + nums[curr]);
            if (max >= nums.size() - 1) return true;
        }
        return false;
    }
};
