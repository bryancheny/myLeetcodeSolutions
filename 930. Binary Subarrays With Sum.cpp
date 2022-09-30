class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) {
            int res = 0, left = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    res += i - left + 1;
                }
                else {
                    left = i + 1;
                }
            }
            return res;
        }
        queue<int>oneLocations; 
        int res = 0;
        int currSum = 0;
        int left = 0;
        int right = -1;
        while (currSum < goal) {
            right ++;
            if (right == nums.size()) return 0;
            if (nums[right]) {
                currSum += 1;
                oneLocations.push(right);
            }
        }
        res += oneLocations.front() - left + 1;
        right++;
        for (; right < nums.size(); right ++) {
            
            if (!nums[right]) {
                res += oneLocations.front() - left + 1;
            }
            else {
                oneLocations.push(right);
                left = oneLocations.front() + 1;
                oneLocations.pop();
                res += oneLocations.front() - left + 1;
            }
        }
        return res;
    }
};
