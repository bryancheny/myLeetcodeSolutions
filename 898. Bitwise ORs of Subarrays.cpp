class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> v; 
        int last = 0;
        for (int i = 0; i < arr.size(); i++) {
            int temp = v.size();
            v.push_back(arr[i]);
            for (; last < temp; last++) {
                int curr = arr[i] | v[last];
                if (v.back() != curr) v.push_back(curr);
            }
            last = temp;
        }
        unordered_set<int> s(v.begin(),v.end());
        return s.size();
    }
};
