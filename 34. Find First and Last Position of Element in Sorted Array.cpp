class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};
        int low = 0, high = nums.size() - 1;
        while (high > low) {
            if (nums[(high+low)/2] > target) {
                high = (high+low)/2 - 1;
            }
            else if (nums[(high+low)/2] < target) {
                low = (high+low)/2 + 1;
            }
            if (nums[(high+low)/2] == target) break;
        }
        if (low >= high) {
            if (nums[low] != target) return {-1,-1};
            else return {low,high};
        }
        int midhigh = (high+low)/2;
        int midlow = (high+low)/2;
        if (nums[high] != target) {
            while (high > midhigh) {
                if (nums[(midhigh+high)/2] == target) {
                    midhigh = (midhigh+high)/2 + 1;
                }
                else high = (midhigh+high)/2;
            }
            high = high - 1;
        }
        if (nums[low] != target) {
            while (low < midlow) {
                if (nums[(midlow+low)/2] == target) {
                    midlow = (midlow+low)/2;
                }
                else low = (midlow+low)/2 + 1;
            }
        }
        return {low,high};
    }
};
