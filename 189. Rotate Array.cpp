class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int begin = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + k) % nums.size();
            if (curr == begin) {
                curr++;
                begin++;
            }
            else swap(nums[begin],nums[curr]);
        }
    }
};
