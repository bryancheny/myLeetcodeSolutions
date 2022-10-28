class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        vector<int> count(ncol - 1);
        int res = pow(2,ncol - 1) * nrow;
        for (int i = 0; i < nrow; i++) {
            if (!grid[i][0]) {
                for (int j = 1; j < grid[i].size(); j++) {
                    count[j-1] += grid[i][j] ^ 1;
                }
            }
            else {
                for (int j = 1; j < grid[i].size(); j++) {
                    count[j-1] += grid[i][j];
                }
            }
        }
        for (int i = 0; i < count.size(); i++) {
            res += pow(2, ncol - i - 2) * max(count[i], nrow - count[i]);
        }
        return res;
    }
};
