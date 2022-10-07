class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int res = 0, left = 0, right = 0;
        long long currRunningCosts = runningCosts[0];
        deque<int> q; // Contains the indices of the max Charge Time robots
        q.push_back(0);
        while (true) {
            if (left > right) {
                if (left == chargeTimes.size()) break;
                right = left; 
                currRunningCosts = runningCosts[right];
                q.push_back(right);
            }
            if (currRunningCosts + chargeTimes[q.front()] <= budget) {
                res = max(res, right - left + 1);
                right ++;
                if (right == chargeTimes.size()) break;
                currRunningCosts = (currRunningCosts / (right - left) + runningCosts[right]) * (right - left + 1);
                while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[right]) {
                    q.pop_back();
                }
                q.push_back(right);
            }
            else {
                if (left == q.front()) {
                    q.pop_front();
                }
                currRunningCosts = (currRunningCosts / (right - left + 1) - runningCosts[left]) * (right - left);
                left ++;
            }
        }
        return res;
    }
};
