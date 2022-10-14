class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.empty()) return 0;

        int res = 1, curr = 1;
        bool isnextLess;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i-1]) {
                curr = 1;
            }
            else if (curr == 1) {
                isnextLess = arr[i] > arr[i-1];
                curr++;
                res = max(curr,res);
            }
            else if ((arr[i] > arr[i-1] && !isnextLess) || (arr[i] < arr[i-1] && isnextLess)) { // part of turbulent array
                isnextLess = !isnextLess;
                curr++;
                res = max(curr,res);
            }
            else { // Not part of turbulent array
                curr = 2;
            }
        }
        return res;
    }
};
