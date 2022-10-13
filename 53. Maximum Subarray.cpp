class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> presum(nums.size()+1);
        presum[0] = 0;
        int currsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i];
            presum[i+1] = currsum;
        }
        int left = 0, right = 1, res = nums[0];
        for (; right < nums.size()+1; right++) {
            res = max(res, presum[right] - presum[left]);
            if (presum[right] < presum[left]) left = right;
        }
        return res;
    }
};
