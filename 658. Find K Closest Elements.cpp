class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int left, right;
        
        // First we find the closest element, initialize both left and right to that closest element's index, then increment left or right from there
        if (it == arr.end()) { // Test for Edge cases
            right = arr.size() - 1;
            left = arr.size() - k;
            return vector<int> (arr.begin() + left, arr.begin() + right + 1);
        }
        if (it == arr.begin()) {
            right = k - 1;
            left = 0; 
            return vector<int> (arr.begin() + left, arr.begin() + right + 1);
        }
        
        if (abs(*(it - 1) - x) <= abs(*it - x)) {
            left = it - 1 - arr.begin();
            right = left;
        }
        else {
            left = it - arr.begin();
            right = left;
        }
        // Main loop starts here
        while (right - left + 1 < k) {
            if (left - 1 < 0)  {
                right = k - 1;
                break;
            }
            else if (right + 1 == arr.size()) {
                left = arr.size() - k;
                break;
            }
            if (abs(arr[left - 1] - x) <= abs(arr[right + 1] - x)) {
                left --;
            }
            else {
                right ++;
            }
        }
        return vector<int> (arr.begin() + left, arr.begin() + right + 1);
    }
};
