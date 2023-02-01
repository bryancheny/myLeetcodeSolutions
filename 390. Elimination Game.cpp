class Solution {
public:
    int lastRemaining(int n) {
        int left = 1;
        int right = n;
        int interval = 1;
        bool leftToRight = true;
        while (left != right) {
            bool isArraySizeOdd = ((right - left) / interval + 1) % 2 == 1; 
            if (leftToRight || isArraySizeOdd) {
                left += interval;
            }
            if (!leftToRight || isArraySizeOdd) {
                right -= interval;
            }
            interval *= 2;
            leftToRight = !leftToRight;
        }
        return left;
    }

};
