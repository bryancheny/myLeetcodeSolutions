class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Record down a sorted array of the smallest last numbers in subsequences of length i
        vector<int> last;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(last.begin(), last.end(), nums[i]);
            if (it == last.end()) {
                last.push_back(nums[i]);   
            }
            else *it = nums[i];
        }
        return last.size();
    }
};
