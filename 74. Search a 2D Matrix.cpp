class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Search vertically first, then search horizontally
        int up = 0, down = matrix.size()-1;
        while (up < down) {
            int mid = (up + down) / 2 + (up + down) % 2;
            if (target < matrix[mid][0]) {
                down = mid - 1;
            }
            else {
                up = mid;
            }
        }
        return binary_search(matrix[up].begin(),matrix[up].end(),target);
    }
};
