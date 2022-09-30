class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> myset;
            for (int j = 0; j < 9; j++) {
                if(isdigit(board[i][j])) {
                    auto pair = myset.insert(board[i][j]);
                    if (!pair.second) return false;
                }
            }
            myset.clear();
            for (int j = 0; j < 9; j++) {
                if(isdigit(board[j][i])) {
                    auto pair = myset.insert(board[j][i]);
                    if (!pair.second) return false;
                }
            }
        }
        for (int i = 0; i <= 6; i+=3) {
            for (int j = 0; j <= 6; j+=3) {
                unordered_set<char> myset;
                for (int a = 0; a <= 2; a++) {
                    for (int b = 0; b <= 2; b++) {
                        if (isdigit(board[i+a][j+b])) {
                            auto pair = myset.insert(board[i+a][j+b]);
                            if (!pair.second) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
