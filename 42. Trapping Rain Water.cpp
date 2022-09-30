class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0;
        int idx = 0;
        int vol = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > max) {
                max = height[i];
                idx = i;
            }
        }
        int currheight = 0;
        for (int i = 0; i < idx; i++) {
            if (height[i] > currheight) {
                currheight = height[i];
            }
            else {
                vol += currheight - height[i];
            }
        }
        currheight = 0;
        for (int i = height.size() - 1; i > idx; i--) {
            if (height[i] > currheight) {
                currheight = height[i];
            }
            else {
                vol += currheight - height[i];
            }
        }
        return vol;
    }
};
