class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<vector<long long>> bigger; // monotonic stack {number, length, sum}
        stack<vector<long long>> smaller; 
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int biggerlen = 1, smallerlen = 1; 
            long long biggersum = nums[i], smallersum = nums[i];
            if (!bigger.empty()) {
                biggersum += bigger.top()[2]; 
                smallersum += smaller.top()[2];  
            }
            while (!bigger.empty() && bigger.top()[0] <= nums[i]) {
                biggersum += (nums[i] - bigger.top()[0]) * bigger.top()[1];
                biggerlen += bigger.top()[1];
                bigger.pop();
            }
            
            bigger.push({nums[i], biggerlen, biggersum});
            while (!smaller.empty() && smaller.top()[0] >= nums[i]) {
                smallersum += (nums[i] - smaller.top()[0]) * smaller.top()[1];
                smallerlen += smaller.top()[1];
                smaller.pop();
            }
            smaller.push({nums[i], smallerlen, smallersum});
            res += bigger.top()[2] - smaller.top()[2];
        }
        return res;
    }
};
