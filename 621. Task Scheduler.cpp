class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        for (auto c:tasks) {
            count[c]++;
        }
        size_t maxcount = 0, nmax = 0;
        for (auto it:count) {
            if (it.second == maxcount) {
                nmax++;
            }
            else if (it.second > maxcount) {
                maxcount = it.second;
                nmax = 1;
            }
        }
        return std::max(tasks.size(), (maxcount-1) * (n+1) + nmax);
    }
};
