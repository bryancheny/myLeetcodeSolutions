class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int i,n=nums.size(), sum=0;
        if(n<2)
            return false;
        m[0]=-1; // 0 sum exists at index -1 
        for(i=0;i<n;i++)
        {
            nums[i]= nums[i]%k;
            sum= sum+nums[i];
            if(m.find((sum)%k) !=m.end() && i-m[(sum)%k]>1) {
                return true;
            }
            if(m.find((sum)%k) ==m.end())
                m[sum%k]=i;
        }
        
        return false;
    }
};
