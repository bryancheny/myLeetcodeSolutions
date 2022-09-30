class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int travelled = startFuel;
        int res = 0;
        while (travelled < target) {
            int maxseen = INT_MIN;
            int it;
            for (int i = 0; i < stations.size(); i++) {
                if (stations[i][0] > travelled) break;
                if (stations[i][1] > maxseen) {
                    maxseen = stations[i][1];
                    it = i;
                } 
            }
            if (maxseen < 0) return -1; // Cannot reach target
            res ++;
            travelled += maxseen;
            stations.erase(stations.begin() + it);
        } 
        return res;
        
    }
};
