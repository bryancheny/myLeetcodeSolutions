class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0; 
        for (auto str: sentences) {
            int currWords = 1;
            for (auto c: str) {
                if (c == ' ') currWords ++;
            }
            maxWords = max(maxWords, currWords);
        }
        return maxWords;
        
    }
};
