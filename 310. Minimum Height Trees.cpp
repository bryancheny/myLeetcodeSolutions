class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       // We just need to remove all leaf nodes until all nodes are leaf nodes
        // On every iteration we must check if the vector contains a non leaf node, O()
        if (n == 1) return {0};
        vector<unordered_set<int>> adj(n,unordered_set<int>());
        vector<int> degrees(n,0);
        int graphsize = n;
        for (auto e:edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
            degrees[e[0]]++;
            degrees[e[1]]++;
        }
        vector<int> toErase;
        for (int i = 0; i<degrees.size(); i++) {
            if(degrees[i] == 1) {
                toErase.push_back(i);
            } 
        }
        while (graphsize > 2) {
            
            vector<int> nextToErase;
            for (auto i:toErase) { 
                int temp = *(adj[i].begin());
                adj[temp].erase(i);
                degrees[temp]--;
                if(degrees[temp] == 1) {
                    nextToErase.push_back(temp);
                }
            }
            graphsize -= toErase.size();
            toErase.swap(nextToErase);
        }
        return toErase;
    }
};
