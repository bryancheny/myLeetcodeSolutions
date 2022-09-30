class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int currSum = 0;
        for (int i = cardPoints.size() - k; i < cardPoints.size(); i++) {
            currSum += cardPoints[i];
        }
        int res = currSum;
        for (int i = 0; i < k; i++) {
            currSum += (cardPoints[i] - cardPoints[cardPoints.size() - k + i]);
            res = max(res,currSum);
        }
        return res;
    }
};
