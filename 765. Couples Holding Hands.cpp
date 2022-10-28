class Solution {
public:
    void dfs(vector<list<int>>& adj, int i, int& cyclesize, unordered_set<int>& visited) {
        if (visited.find(i) != visited.end()) return;
        visited.insert(i);
        cyclesize++;
        for (auto &j: adj[i]) {
            dfs(adj,j,cyclesize,visited);
        }
    }
    int minSwapsCouples(vector<int>& row) {
        vector<list<int>> adj(row.size()/2, list<int>());
        for (int i = 0; i < row.size(); i = i + 2) {
            if (row[i] / 2 != row[i+1] / 2) {
                adj[row[i]/2].push_back(row[i+1]/2);
                adj[row[i+1]/2].push_back(row[i]/2);
            }
        }
        unordered_set<int> visited;
        int res = 0;
        for (int i = 0; i < adj.size(); i++) {
            int cyclesize = 0;
            dfs(adj, i, cyclesize, visited);
            if (cyclesize > 1) res += cyclesize - 1;            
        }
        return res;
    }
};
