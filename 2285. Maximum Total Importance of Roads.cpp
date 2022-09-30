class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        map<int,int> count; // maps degree to number of nodes with that degree
        long long res = 0;
        int curr = 1;
        for (int i = 0; i < roads.size(); i++) {
            degree[roads[i][0]] ++;
            degree[roads[i][1]] ++; 
        }
        for (auto &i : degree) {
            count[i]++;
        }
        for (auto it:count) {
            long long temp = (curr + curr + it.second - 1);
            long long temp2 = it.second * it.first;
            res += temp * temp2 / 2;
            curr += it.second;
        }
        return res;
    }
};
