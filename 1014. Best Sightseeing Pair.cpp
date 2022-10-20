class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // Go from left
        int l = values[0], res = INT_MIN; // values[i] + i
        for (int i = 1; i < values.size(); i++) {
            res = max(res, l + values[i] - i);
            l = max(l, values[i] + i);
        }
        return res;
    }
};
