class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Loop from back, see if increasing order
        for (int i = nums.size()-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                auto it = upper_bound(nums.rbegin(),nums.rbegin()+nums.size()-i-1,nums[i]);
                iter_swap(it,nums.rbegin()+nums.size()-i-1);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
        
    }
};
