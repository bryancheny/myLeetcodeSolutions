class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> count;
        for (auto &i:nums) {
            count[i]++;
        }
        vector<int> frequencies;
        for (auto i:count) {
            frequencies.push_back(i.second);
        }
        sort(frequencies.begin(),frequencies.end());
        int cutoff = frequencies[frequencies.size() - k];
        vector<int> res;
        for (auto i:count) {
            if(i.second >= cutoff) res.push_back(i.first);
        }
        return res;
    }
};
