class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> mset(nums1.begin(),nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (*mset.rbegin() <= nums2[i]) {
                nums1[i] = *mset.begin();
                mset.erase(mset.begin());
            }
            else {
                auto it = mset.upper_bound(nums2[i]);
                nums1[i] = *it;
                mset.erase(it);
            }
        }
        return nums1;
    }
};
