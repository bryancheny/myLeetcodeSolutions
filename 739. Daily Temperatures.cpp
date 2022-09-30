class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        unordered_map<int,int> temtoidx;
        set<int> myset;
        
        for (int i = temperatures.size()-1; i >= 0; i--) {
            auto it = myset.insert(temperatures[i]);
            for (auto it2 = myset.begin(); it2 != it.first; it2++) {
                myset.erase(it2);
            }
            temtoidx[temperatures[i]] = i;
            if (++it.first == myset.end()) res[i] = 0;
            else {
                res[i] = temtoidx[*it.first] - i; 
            }
        }
        
        return res;
    }
};
