class Solution {
public:
    bool canReach (vector<int>& arr, int start) { // record visited indices by writing them to be -1
        if (start >= arr.size() || start < 0 || arr[start] == -1){
            return false;
        } 
        if (arr[start] == 0) return true;
        int temp = arr[start];
        arr[start] = -1;
        return canReach(arr,start + temp) || canReach(arr,start - temp);
    }
};
