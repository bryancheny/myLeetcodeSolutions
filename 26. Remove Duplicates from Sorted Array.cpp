class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 1;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (curr != nums[i]) {
                curr = nums[i];
                swap(nums[i],nums[unique]);
                unique++;
            }
        }
        return unique;
    }
};
